#pragma once

struct reader_s
{
    
};

typedef struct reader_s reader;

int reader_construct ( const reader **pp_reader, int (*pfn_blocking_operation)(int argc, ...) );