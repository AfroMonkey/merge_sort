#include <iostream>

#include "merge_sort.hpp"

#define NUM 5000

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main(int argc, char const *argv[])
{
    int array[NUM];
    for (int i = 0; i < NUM; i++)
    {
        array[i] = std::rand();
    }
    std::cout << "Start" << std::endl;
    afro_merge(array, NUM, sizeof(int), compare);
    std::cout << "End" << std::endl;
    return 0;
}
