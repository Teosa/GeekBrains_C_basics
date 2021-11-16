#pragma once

#include <cstdlib>
#include <iostream>

namespace some_namespace
{
    void initArray(float* pArray, const size_t arraySize);
    void printArray(float* pArray, const size_t arraySize);
    void countPositiveAndNegative(float* pArray, const size_t arraySize);

    void initArray(int* pArray, const size_t arraySize);
    void sortArray(int* pArray, const size_t arraySize);
    void printArray(int* pArray, const size_t arraySize);
    
}

