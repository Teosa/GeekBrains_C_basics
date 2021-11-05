#include <iostream>

int main()
{
    setlocale(LC_CTYPE, "rus");

    /* Задание 1
     * Написать программу, проверяющую что сумма двух (введенных с клавиатуры) чисел лежит
     * в пределах от 10 до 20 (включительно), если да – вывести строку "true", в противном случае – "false";
     */

    int firstValue, secondValue;

    std::cout << "Введите первое число: " << std::endl;
    std::cin >> firstValue;

    std::cout << "Введите второе число: " << std::endl;
    std::cin >> secondValue;

    const int sum = firstValue + secondValue;

    const std::string sumAnalyzeResult = sum >= 10 && sum <= 20 ? "true" : "false";

    std::cout << sumAnalyzeResult << std::endl;

    /* Задание 2
     * Написать программу, выводящую на экран строку “true”, если две целочисленные константы (или просто числа),
     * объявленные в её начале либо обе равны десяти сами по себе, либо их сумма равна десяти. Иначе "false".
     */
    constexpr int firstConst = 56;
    constexpr int secondConst = 10;

    if ((firstConst == 10 && secondConst == 10) || firstConst + secondConst == 10)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }


    /* Задание 3
     * Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50.
     * Например: "Your numbers: 1 3 5 7 9 11 13 …". Для решения используйте любой С++ цикл.
     */
    constexpr size_t LOOP_LENGTH = 50;

    for (int i = 1; i <= LOOP_LENGTH; ++i)
    {
        if (i % 2 != 0)
        {
            std::cout << i;
            std::cout << " ";
        }
    }

    return 0;
}
