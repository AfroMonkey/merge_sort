#ifndef AFRO_MERGE_SORT_HPP
#define AFRO_MERGE_SORT_HPP
#include <cstdlib> // size_t, malloc
#include <cstring> // memcpy

void _merge(void* base, void* left, void* right, size_t middle, size_t middle2, size_t size, int((*compare)(const void*, const void*)))
{
    size_t i, j, k;
    for (i = 0, j = 0, k = 0; i < middle && j < middle2; k++)
    {
        if (compare((char*)left + i * size, (char*)right + j * size) < 0)
        {
            memcpy((char*)base + k * size, (char*)left + i * size, size);
            i++;
        }
        else
        {
            memcpy((char*)base + k * size, (char*)right + j * size, size);
            j++;
        }
    }
    if (i < middle)
    {
        memcpy((char*)base + k * size, (char*)left + i * size, (middle - i) * size);
    }
    if (j < middle2)
    {
        memcpy((char*)base + k * size, (char*)right + j * size, (middle2 - j) * size);
    }
}

void afro_merge(void* base, size_t num, size_t size, int((*compare)(const void*, const void*)))
{
    if (num > 1)
    {
        size_t middle = num / 2;
        size_t middle2 = num - middle;
        void* left = (void*)malloc(middle * size);
        void* right = (void*)malloc(middle2 * size);
        memcpy(left, base, middle * size);
        memcpy(right, (char*)base + middle * size, middle2 * size);
        afro_merge(left, middle, size, compare);
        afro_merge(right, num - middle, size, compare);
        _merge(base, left, right, middle, middle2, size, compare);
        free(left);
        free(right);
    }
}

#endif
