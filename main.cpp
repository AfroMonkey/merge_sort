#include <iostream>

#include "merge_sort.hpp"

#define NUM 50000

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main(int argc, char const *argv[])
{
    int array[NUM];
    for (int i = 0; i < NUM; i++)
    {
        array[NUM] = std::rand();
    }
    std::cout << "Start" << std::endl;
    afro_merge(array, NUM, sizeof(int), compare);
    for (int i = 1; i < NUM; i++) // TODO [REM]
    {
        if (array[i] < array[i-1])
        {
            std::cout << "Error" << std::endl;
            std::cout << array[i-1] << "<" << array[i] << std::endl;
            break;
        }
    }
    std::cout << "End" << std::endl;
    return 0;
}
