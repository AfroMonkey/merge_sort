#ifndef AFRO_MERGE_SORT_HPP
#define AFRO_MERGE_SORT_HPP
#include <cstdlib> // size_t, malloc
#include <cstring> // memcpy

void afro_swap(void* a, void* b, size_t size)
{
    char *c = (char*)malloc(size);
    std::memcpy(c,a,size);
    std::memcpy(a,b,size);
    std::memcpy(b,c,size);
    free(c);
}

void afro_merge(void* base, size_t num, size_t size, int((*compare)(const void*, const void*)))
{
    // TODO
}

#endif
