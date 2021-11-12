#include <iostream>

int main()
{
    setlocale(LC_CTYPE, "rus");

    /* ������� 1
     * �������� ���������, ����������� ��� ����� ���� (��������� � ����������) ����� �����
     * � �������� �� 10 �� 20 (������������), ���� �� � ������� ������ "true", � ��������� ������ � "false";
     */

    int firstValue, secondValue;

    std::cout << "������� ������ �����: " << std::endl;
    std::cin >> firstValue;

    std::cout << "������� ������ �����: " << std::endl;
    std::cin >> secondValue;

    const int sum = firstValue + secondValue;

    const std::string sumAnalyzeResult = sum >= 10 && sum <= 20 ? "true" : "false";

    std::cout << sumAnalyzeResult << std::endl;

    /* ������� 2
     * �������� ���������, ��������� �� ����� ������ �true�, ���� ��� ������������� ��������� (��� ������ �����),
     * ����������� � � ������ ���� ��� ����� ������ ���� �� ����, ���� �� ����� ����� ������. ����� "false".
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


    /* ������� 3
     * �������� ��������� ������� ������� �� ����� ������ ���� �������� ����� �� 1 �� 50.
     * ��������: "Your numbers: 1 3 5 7 9 11 13 �". ��� ������� ����������� ����� �++ ����.
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
