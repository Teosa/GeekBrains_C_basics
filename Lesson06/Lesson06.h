#ifndef LESSON06_H
#define LESSON06_H
#include <string>

const std::string EXTENSION = ".txt";

void task01();
void task02();
void task03();
void task04();
void task05();

void printArray(const int* pArray, const size_t arraySize);
void fillArray(int* pArray, const size_t arraySize);
void initMatrix(int **pMatrix, size_t MATRIX_SIZE);
void fillMatrix(int **pMatrix, size_t MATRIX_SIZE);
void printMatrix(int **pMatrix, size_t MATRIX_SIZE);
void clearMatrix(int **pMatrix, size_t MATRIX_SIZE);
void createFile();
void concatFiles(std::string firstFileName, std::string secondFileName, std::string resultFileName);
void writeFileToFile(std::ifstream &source, std::ofstream &target);
bool findWordInFile(std::string fileName, std::string word);

#endif
