#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Eng.cpp"
#include "Ukr.cpp"
#include "Ger.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Проверка работоспособности программы" << endl;
	ConvertToEnglish Convert;
	cout << Convert.ConvertToEng(225) << endl;
	ConvertToUkrainian Text;
	cout << Text.ConvertToUa(225) << endl;
	ConvertToGermany Number;
	cout << Number.ConvertToGer(225) << endl;
	int x;
	cin >> x;
    return 0;
	system("pause");
	_getch();
}

