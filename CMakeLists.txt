# Need CMake 3.28.0
cmake_minimum_required (VERSION 3.28.0)

# The name of the repository
project ("distribute")

# Comment out for Debug mode
set(IS_DEBUG_BUILD CMAKE_BUILD_TYPE STREQUAL "Debug")

# Set the correct paths
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/extern/)

# Find the log module
if ( NOT "${HAS_LOG}")
    
    # Add the log directory
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/log ${CMAKE_SOURCE_DIR}/build/log)

    # Let any parent project know that this project has log
    if(NOT PROJECT_IS_TOP_LEVEL)
        set(HAS_LOG true PARENT_SCOPE)
        set(LOG_INCLUDE_DIR ${LOG_INCLUDE_DIR} PARENT_SCOPE)
    endif()
endif()

# Find the queue module
if ( NOT "${HAS_QUEUE}")
    
    # Add the queue directory
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/queue ${CMAKE_SOURCE_DIR}/build/queue)

    # Let any parent project know that this project has queue
    if(NOT PROJECT_IS_TOP_LEVEL)
        set(HAS_QUEUE true PARENT_SCOPE)
        set(QUEUE_INCLUDE_DIR ${QUEUE_INCLUDE_DIR} PARENT_SCOPE)
    endif()
endif()

# Find the array module
if ( NOT "${HAS_JSON}")
    
    # Add the array directory
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/json ${CMAKE_SOURCE_DIR}/build/json)

    # Let any parent project know that this project has array
    if(NOT PROJECT_IS_TOP_LEVEL)
        set(HAS_JSON true PARENT_SCOPE)
        set(JSON_INCLUDE_DIR ${JSON_INCLUDE_DIR} PARENT_SCOPE)
    endif()
endif()

# Find the array module
if ( NOT "${HAS_ARRAY}")
    
    # Add the array directory
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/array ${CMAKE_SOURCE_DIR}/build/array)

    # Let any parent project know that this project has array
    if(NOT PROJECT_IS_TOP_LEVEL)
        set(HAS_ARRAY true PARENT_SCOPE)
        set(ARRAY_INCLUDE_DIR ${ARRAY_INCLUDE_DIR} PARENT_SCOPE)
    endif()
endif()

# Find the dict module
if ( NOT "${HAS_DICT}")
    
    # Add the dict directory
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/dict ${CMAKE_SOURCE_DIR}/build/dict)

    # Let any parent project know that this project has dict
    if(NOT PROJECT_IS_TOP_LEVEL)
        set(HAS_DICT true PARENT_SCOPE)
        set(DICT_INCLUDE_DIR ${DICT_INCLUDE_DIR} PARENT_SCOPE)
    endif()
endif()

# Find the parallel module
if ( NOT "${HAS_PARALLEL}")
    
    # Add the parallel directory
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/parallel ${CMAKE_SOURCE_DIR}/build/parallel)

    # Let any parent project know that this project has parallel
    if(NOT PROJECT_IS_TOP_LEVEL)
        set(HAS_PARALLEL true PARENT_SCOPE)
        set(PARALLEL_INCLUDE_DIR ${PARALLEL_INCLUDE_DIR} PARENT_SCOPE)
    endif()
endif()

# Find the async module
if ( NOT "${HAS_ASYNC}")
    
    # Add the async directory
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/async ${CMAKE_SOURCE_DIR}/build/async)

    # Let any parent project know that this project has async
    if(NOT PROJECT_IS_TOP_LEVEL)
        set(HAS_ASYNC true PARENT_SCOPE)
        set(ASYNC_INCLUDE_DIR ${ASYNC_INCLUDE_DIR} PARENT_SCOPE)
    endif()
endif()

# Find the socket module
if ( NOT "${HAS_SOCKET}")
    
    # Add the socket directory
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/socket ${CMAKE_SOURCE_DIR}/build/socket)

    # Let any parent project know that this project has socket
    if(NOT PROJECT_IS_TOP_LEVEL)
        set(HAS_SOCKET true PARENT_SCOPE)
        set(SOCKET_INCLUDE_DIR ${SOCKET_INCLUDE_DIR} PARENT_SCOPE)
    endif()
endif()

# Add the distribute project
if ( NOT "${HAS_DISTRIBUTE}")

    set (DISTRIBUTE_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

    # Let any parent project know that it has the log project
    if(NOT PROJECT_IS_TOP_LEVEL)
        set(HAS_DISTRIBUTE true PARENT_SCOPE)
        set(DISTRIBUTE_INCLUDE_DIR ${DISTRIBUTE_INCLUDE_DIR} PARENT_SCOPE)
    endif()
endif()

# Comment out for Debug mode
set(IS_DEBUG_BUILD CMAKE_BUILD_TYPE STREQUAL "Debug")

if (${IS_DEBUG_BUILD})
    add_compile_definitions(NDEBUG)
endif ()

# Add source to this project's executable.
add_executable (distribute_example "main.c")
add_dependencies(distribute_example distribute async parallel log crypto json array dict sync socket)
target_include_directories(distribute_example PUBLIC ${DISTRIBUTE_INCLUDE_DIR} ${ASYNC_INCLUDE_DIR} ${PARALLEL_INCLUDE_DIR} ${QUEUE_INCLUDE_DIR} ${ARRAY_INCLUDE_DIR} ${DICT_INCLUDE_DIR} ${SYNCL_INCLUDE_DIR} ${LOG_INCLUDE_DIR} ${CRYPTO_INCLUDE_DIR} ${SOCKET_INCLUDE_DIR})
target_link_libraries(distribute_example distribute async parallel queue log crypto parallel json array dict sync socket)

## Add source to the tester
#

# Add source to this project's library
add_library (distribute SHARED "distribute.c" "connection.c")
add_dependencies(distribute async parallel log crypto json array dict sync socket)
target_include_directories(distribute PUBLIC ${DISTRIBUTE_INCLUDE_DIR} ${ASYNC_INCLUDE_DIR} ${PARALLEL_INCLUDE_DIR} ${QUEUE_INCLUDE_DIR} ${ARRAY_INCLUDE_DIR} ${DICT_INCLUDE_DIR} ${SYNCL_INCLUDE_DIR} ${LOG_INCLUDE_DIR} ${CRYPTO_INCLUDE_DIR} ${SOCKET_INCLUDE_DIR})
target_link_libraries(distribute PRIVATE async parallel queue log crypto json array dict sync socket)
