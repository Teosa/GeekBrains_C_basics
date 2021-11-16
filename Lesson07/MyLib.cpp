#include "MyLib.h"

namespace some_namespace
{
    void initArray(float* pArray, const size_t arraySize)
    {
        for (int i = 0; i < arraySize; ++i)
        {
            pArray[i] = rand() % 19 + (-9);;
        }
    }

    void printArray(float* pArray, const size_t arraySize)
    {
        for (int i = 0; i < arraySize; ++i)
        {
            std::cout << pArray[i];

            if (i == arraySize - 1)
            {
                std::cout << "" << std::endl;
            }
            else
            {
                std::cout << " ";
            }
        }
    }

    void countPositiveAndNegative(float* pArray, const size_t arraySize)
    {
        int pos = 0, neg = 0;

        for (int i = 0; i < arraySize; ++i)
        {
            if (pArray[i] < 0)
            {
                neg++;
            }
            else
            {
                pos++;
            }
        }

        std::cout << "Positive count: " << pos << " Negative count: " << neg << std::endl;
    }

    void initArray(int* pArray, const size_t arraySize)
    {
        int tmp;

        for (int i = 0; i < arraySize; ++i)
        {
            std::cout << "Enter number " << i + 1 << std::endl;
            std::cin >> tmp;

            pArray[i] = tmp;
        }
    }

    void sortArray(int* pArray, const size_t arraySize)
    {
        bool sorted = false, changed = false;
        int tmp;
        
        while (!sorted)
        {
            for (int i = 0; i < arraySize - 1; ++i)
            {
                if (pArray[i] > pArray[i + 1])
                {
                    tmp = pArray[i + 1];
                    pArray[i + 1] = pArray[i];
                    pArray[i] = tmp;
                    changed = true;
                }

                if (i == arraySize - 2)
                {
                    if (changed == true) changed = false;
                    else sorted = true;
                }
            }
        }
    }

    void printArray(int* pArray, const size_t arraySize)
    {
        for (int i = 0; i < arraySize; ++i)
        {
            std::cout << pArray[i];

            if (i == arraySize - 1)
            {
                std::cout << "" << std::endl;
            }
            else
            {
                std::cout << " ";
            }
        }
    }
}
