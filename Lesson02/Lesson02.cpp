
#include <iostream>

int main()
{
    // 1. Создать и инициализировать переменные пройденных типов данных (short int, int, long long, char, bool, float, double).
    short int  shortIntVar = 200;
    int        intVar = 1'500'000;
    long long  longLongVar = 256'300'000'000;
    char       charVar = 'N';
    bool       boolVar = true;
    float      floatVar = -2.89f;
    double     doubleVar = 16.0000000001;

    // 2. Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики.
    enum GameSymbols
    {
        EMPTY, // value = 0
        ZERO,  // value = 1
        CROSS  // value = 2
    };
    
    // 3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
    GameSymbols gameState[] = { EMPTY, EMPTY, ZERO, CROSS, CROSS, EMPTY, EMPTY, EMPTY, ZERO };

    // 4. * Создать структуру (struct) данных «Поле для игры в крестики-нолики» и
    //      снабдить его всеми необходимыми свойствами (подумайте что может понадобиться).
    struct Player
    {
        std::string name;
        GameSymbols symbol;
    };
    
    struct GameField
    {
        GameSymbols field[3][3];
        Player firstPlayer { "Player1", ZERO };
        Player secondPlayer { "Player2", CROSS };
        Player currentPlayer = firstPlayer; // Игрок, чья очередь хода в данный попент. Инициализируем первым игроком, т.к. О ходят первыми
    };

    // 5. ** Создать структуру (struct MyVariant) объединяющую: union MyData (int, float, char) и 3-и битовых поля (флага)
    //       указывающими какого типа значение в данный момент содержится в объединении (isInt, isFloat, isChar).
    //       Продемонстрировать пример использования в коде этой структуры.

    union MyData
    {
        int   intValue;
        float floatValue;
        char  charValue;
    };
    
    struct MyVariant
    {
        MyData   myData;
        unsigned isInt : 1;
        unsigned isFloat : 1;
        unsigned isChar : 1;
    };
    
    MyVariant myVariant { {6}, 1,0,0 };

    if(myVariant.isInt)
    {
        std::cout << myVariant.myData.intValue << std::endl;
    }
    else if (myVariant.isFloat)
    {
        std::cout << myVariant.myData.floatValue << std::endl;
    }
    else if (myVariant.isChar)
    {
        std::cout << myVariant.myData.charValue << std::endl;
    }

    myVariant.myData.charValue = 'Q';
    myVariant.isChar = 1;
    myVariant.isInt = 0;

    if(myVariant.isInt)
    {
        std::cout << myVariant.myData.intValue << std::endl;
    }
    else if (myVariant.isFloat)
    {
        std::cout << myVariant.myData.floatValue << std::endl;
    }
    else if (myVariant.isChar)
    {
        std::cout << myVariant.myData.charValue << std::endl;
    }
    
    return 0;
}

