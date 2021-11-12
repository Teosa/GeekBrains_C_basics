#include <iostream>
void printArray(const double* pArray, const size_t arraySize);
void printArray(const int* pArray, const size_t arraySize);
void modifyArray(int* pArray, const size_t arraySize);
void fillArray(int* pArray, const size_t arraySize);
void scrollArray(int* pArray, const size_t arraySize, int scrollIndex);
bool checkBalance(const int* pArray, const size_t arraySize);

int main()
{
    /* Задание 1
     * Написать функцию которая выводит массив double чисел на экран.
     * Параметры функции это сам массив и его размер. Вызвать эту функцию из main.
     */
    const size_t ARRAY_SIZE_TASK_1 = 5;
    constexpr double doublesArray[ARRAY_SIZE_TASK_1] = {5.0004, -84.47654, 0, 0.0000012, 1.33333333333};

    printArray(doublesArray, ARRAY_SIZE_TASK_1);

    /* Задание 2
     * Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ].
     * Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.
     */

    const size_t ARRAY_SIZE_TASK_2 = 10;
    int intsArray[ARRAY_SIZE_TASK_2] = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};

    printArray(intsArray, ARRAY_SIZE_TASK_2);
    modifyArray(intsArray, ARRAY_SIZE_TASK_2);
    printArray(intsArray, ARRAY_SIZE_TASK_2);

    /* Задание 3
     * Задать пустой целочисленный массив размером 8.
     * Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22.
     * Вывести массив на экран.
     */

    const size_t ARRAY_SIZE_TASK_3 = 8;
    int newArray[ARRAY_SIZE_TASK_3];

    fillArray(newArray, ARRAY_SIZE_TASK_3);
    printArray(newArray, ARRAY_SIZE_TASK_3);

    /* Задание 4
     * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным),
     * при этом метод должен циклически сместить все элементы массива на n позиций.
     */
    const size_t ARRAY_SIZE_TASK_4 = 10;
    int simpleArray[ARRAY_SIZE_TASK_4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printArray(simpleArray, ARRAY_SIZE_TASK_4);
    scrollArray(simpleArray, ARRAY_SIZE_TASK_4, 3);
    printArray(simpleArray, ARRAY_SIZE_TASK_4);

    /* Задание 5
     * Написать функцию, которой передается не пустой одномерный целочисленный массив,
     * она должна вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны.
     * Примеры:
     * checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
     * checkBalance ([10, || 1, 2, 3, 4]) → true.
     * Абстрактная граница показана символами ||, эти символы в массив не входят.
     */
    const size_t ARRAY_SIZE_TASK_5 = 5;

    int balancedArrayA[ARRAY_SIZE_TASK_5] = {1, 1, 1, 2, 1};
    int notBalancedArrayA[ARRAY_SIZE_TASK_5] = {2, 1, 1, 2, 1};
    int balancedArrayB[ARRAY_SIZE_TASK_5] = {10, 1, 2, 3, 4};

    std::cout << checkBalance(balancedArrayA, ARRAY_SIZE_TASK_5) << std::endl;
    std::cout << checkBalance(notBalancedArrayA, ARRAY_SIZE_TASK_5) << std::endl;
    std::cout << checkBalance(balancedArrayB, ARRAY_SIZE_TASK_5) << std::endl;

    return 0;
}

void printArray(const double* pArray, const size_t arraySize)
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

void printArray(const int* pArray, const size_t arraySize)
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

void modifyArray(int* pArray, const size_t arraySize)
{
    for (int i = 0; i < arraySize; ++i)
    {
        if (pArray[i] == 0)
        {
            pArray[i] = 1;
        }
        else
        {
            pArray[i] = 0;
        }
    }
}

void fillArray(int* pArray, const size_t arraySize)
{
    for (int i = 0, k = 1; i < arraySize; ++i, k += 3)
    {
        pArray[i] = k;
    }
}

void scrollArray(int* pArray, const size_t arraySize, int scrollIndex)
{
    if (scrollIndex == 0) return;

    int tmpVar;
    const bool isScrollPositive = scrollIndex > 0;
    int scroll;

    if (isScrollPositive)
    {
        scrollIndex = arraySize - scrollIndex;
        scroll = 1;
    }
    else
    {
        scroll = -1;
    }

    for (int i = 0; i < scrollIndex * scroll; ++i)
    {
        for (int k = 1; k < arraySize; ++k)
        {
            tmpVar = pArray[k];
            pArray[k] = pArray[k - 1];
            pArray[k - 1] = tmpVar;
        }
    }
}

bool checkBalance(const int* pArray, const size_t arraySize)
{
    int leftPartSum = 0, rightPartSum = 0;

    for (int i = 0; i < arraySize; ++i)
    {
        leftPartSum += pArray[i];

        for (int k = arraySize - 1; k > i; --k)
        {
            rightPartSum += pArray[k];
        }

        if (rightPartSum == leftPartSum)
        {
            return true;
        }

        rightPartSum = 0;
    }

    return false;
}
