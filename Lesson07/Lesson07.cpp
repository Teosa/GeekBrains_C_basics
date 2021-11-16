#include "MyLib.h"

#define CHECK_RANGE(num, max) num >= 0 && num < max
#define TASK03_ARRAY_SIZE 5

/* Задание 1 и 5
 * Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции:
 * для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов.
 * Вызывайте эти 3-и функции из main для работы с массивом.
 */
void task01And05()
{
    const size_t ARRAY_SIZE = 5;
    float* myArray = new float[ARRAY_SIZE];

    some_namespace::initArray(myArray, ARRAY_SIZE);
    some_namespace::printArray(myArray, ARRAY_SIZE);
    some_namespace::countPositiveAndNegative(myArray, ARRAY_SIZE);

    delete[] myArray;
}

/* Задание 2
 * Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры)
 * в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false,
 * вывести на экран «true» или «false».
 */
void task02()
{
    int number, maxRange;

    std::cout << "Введите целое число" << std::endl;
    std::cin >> number;

    std::cout << "Введите второе цело число" << std::endl;
    std::cin >> maxRange;

    const bool result = CHECK_RANGE(number, maxRange);
    std::cout << (result ? "true" : "false") << std::endl;
}

/* Задание 3
 * Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define.
 * Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком).
 * Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
 */
void task03()
{
    int* myArray = new int[TASK03_ARRAY_SIZE];

    some_namespace::initArray(myArray, TASK03_ARRAY_SIZE);
    some_namespace::sortArray(myArray, TASK03_ARRAY_SIZE);
    some_namespace::printArray(myArray, TASK03_ARRAY_SIZE);
    
    delete[] myArray;
}

int main()
{
    setlocale(LC_CTYPE, "rus");

    task01And05();
    task02();
    task03();

    return 0;
}
