/** !
 * Async I/O
 *
 * @file async/async.h
 * 
 * @author Jacob Smith
 */

// header guard
#pragma once

// header files
#include <async/async.h>

// platform dependent macros
#ifdef _WIN64
#define DLLEXPORT extern __declspec(dllexport)
#else
#define DLLEXPORT
#endif

// set dict reallocator
#ifdef DICT_REALLOC
    #undef DICT_REALLOC
    #define DICT_REALLOC(p, sz) realloc(p, sz)
#endif

// set array reallocator
#ifdef ARRAY_REALLOC
    #undef ARRAY_REALLOC
    #define ARRAY_REALLOC(p, sz) realloc(p, sz)
#endif

// set json reallocator
#ifdef JSON_REALLOC
    #undef JSON_REALLOC
    #define JSON_REALLOC(p, sz) realloc(p, sz)
#endif

// set parallel reallocator
#ifdef PARALLEL_REALLOC
    #undef PARALLEL_REALLOC
    #define PARALLEL_REALLOC(p, sz) realloc(p, sz)
#endif

// memory management macro
#ifndef ASYNC_REALLOC
    #define ASYNC_REALLOC(p, sz) realloc(p,sz)
#endif

// function declarations
/** !
 * Construct a raeder
 * 
 * @param p_reader
 * 
 * @return 1 on success, 0 on error
 */
DLLEXPORT int reader_construct ( const reader **pp_reader, int (*pfn_blocking_operation)(int argc, ...) )
{

    

    // Success
    return 1;
}