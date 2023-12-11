// AoC_2023.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "stringHelper.h"
#include "01.h"
#include "02.h"
#include "03.h"
#include "xx.h"

int main()
{
    int day = 2;

    switch (day)
    {
    case 1:
        main_01();
        break;

    case 2:
        main_02();
        break;

    case 3:
        main_03();
        break;

    case 99:
        main_xx();
        break;

    default:
        cout << "wrong day input";
    }

    return 0;
}
