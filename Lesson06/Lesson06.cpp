#include "Lesson06.h"

#include <fstream>
#include <iostream>

int main()
{
    setlocale(LC_CTYPE, "rus");

    task01();
    task02();
    task03();
    task04();
    task05();
    
    return 0;
}

/* Задание 1
* Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя.
* Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 ...
* Вывести массив на экран. Не забыть освободить память. =) Разбить программу на функции.
*/
void task01()
{
    size_t ARRAY_SIZE;

    std::cout << "Введите размер массива" << std::endl;
    std::cin >> ARRAY_SIZE;

    int* pArray = new int[ARRAY_SIZE];

    fillArray(pArray, ARRAY_SIZE);
    printArray(pArray, ARRAY_SIZE);

    delete[] pArray;
    pArray = nullptr;
}

/* Задание 2
 * Динамически выделить матрицу 4х4 типа int.
 * Инициализировать ее псевдослучайными числами через функцию rand.
 * Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.
 */
void task02()
{
    const size_t MATRIX_SIZE = 4;
    int** pMatrix = new int*[MATRIX_SIZE];

    initMatrix(pMatrix, MATRIX_SIZE);
    fillMatrix(pMatrix, MATRIX_SIZE);
    printMatrix(pMatrix, MATRIX_SIZE);
    clearMatrix(pMatrix, MATRIX_SIZE);
}

/* Задание 3
 * Написать программу, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым).
 * Имена файлов запросить у польлзователя.
 */
void task03()
{
    createFile();
    createFile();
}

/* Задание 4
 * Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
 */
void task04()
{
    std::string firstFileName;
    std::string secondFileName;
    std::string resultFileName;

    std::cout << "Введите имя первого файла" << std::endl;
    std::cin >> firstFileName;
    std::cout << "Введите имя второго файла" << std::endl;
    std::cin >> secondFileName;
    std::cout << "Введите имя результирующего файла" << std::endl;
    std::cin >> resultFileName;

    concatFiles(firstFileName, secondFileName, resultFileName);
}

/* Задание 5
 * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в
 * указанном пользователем файле (для простоты работаем только с латиницей).
 * Используем функцию find которая есть в строках std::string.
 */
void task05()
{
    std::string fileName;
    std::string word;
    
    std::cout << "Введите имя файла" << std::endl;
    std::cin >> fileName;
    std::cout << "Введите слово для поиска" << std::endl;
    std::cin >> word;

    bool result = findWordInFile(fileName, word);

    if(result) std::cout << "Слово " + word + " найдено." << std::endl;
    else std::cout << "Слово " + word + " не найдено." << std::endl;
}

bool findWordInFile(std::string fileName, std::string word)
{
    bool result = false;
    
    std::ifstream file(fileName + EXTENSION);

    if(file.is_open())
    {
        std::string bufferString;
        while (!file.eof())
        {
            std::getline(file, bufferString);

            if(bufferString.find(word) != std::string::npos)
            {
                result = true;
                break;
            }
        }

        file.close();
    }

    return result;
}

void concatFiles(std::string firstFileName, std::string secondFileName, std::string resultFileName)
{
    std::ifstream firstFile(firstFileName + EXTENSION);
    std::ifstream secondFile(secondFileName + EXTENSION);

    std::ofstream resultFile(resultFileName + EXTENSION);

    writeFileToFile(firstFile, resultFile);
    writeFileToFile(secondFile, resultFile);

    firstFile.close();
    secondFile.close();
    resultFile.close();
}

void writeFileToFile(std::ifstream& source, std::ofstream& target)
{
    if (source.is_open() && target.is_open())
    {
        std::string bufferString;
        while (!source.eof())
        {
            std::getline(source, bufferString);
            target << bufferString << std::endl;
        }

        target << std::endl;
    }
}

void createFile()
{
    std::string fileName;

    std::cout << "Введите имя файла" << std::endl;
    std::cin >> fileName;

    std::ofstream file(fileName + EXTENSION);

    file << "First string" << std::endl;
    file << "Second string" << std::endl;
    file << "Third string" << std::endl;
    file << "Fourth string" << std::endl;

    file.close();
}

void initMatrix(int** pMatrix, size_t MATRIX_SIZE)
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        pMatrix[i] = new int[MATRIX_SIZE];
    }
}

void fillMatrix(int** pMatrix, size_t MATRIX_SIZE)
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        for (int k = 0; k < MATRIX_SIZE; ++k)
        {
            pMatrix[i][k] = rand() % 100 + 1;
        }
    }
}

void clearMatrix(int** pMatrix, size_t MATRIX_SIZE)
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        delete[] pMatrix[i];
    }

    delete[] pMatrix;
    pMatrix = nullptr;
}

void printMatrix(int** pMatrix, size_t MATRIX_SIZE)
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        for (int k = 0; k < MATRIX_SIZE; ++k)
        {
            std::cout << pMatrix[i][k] << " ";
        }

        std::cout << std::endl;
    }
}

void fillArray(int* pArray, const size_t arraySize)
{
    for (int i = 0; i < arraySize; ++i)
    {
        if (i == 0) pArray[i] = 1;
        else pArray[i] = pArray[i - 1] * 2;
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
