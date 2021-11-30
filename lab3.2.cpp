﻿#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите полученное значение" << endl;
	unsigned short x;
	cin >> hex >> x; // ввод шестнадцатиричного числа

	if (x < 0xfff9) // проверка на максимальное возможное число
	{
		unsigned short S, G, P;

		P = (x >> 3) & 0x1; // аналогично с остальными
		if (P == 1) // у числа P  может быть только два значения, поэтому пользуемся функцией if 
			cout << "Пользователь привилегирован" << endl;

		else  cout << "Пользователь непривилегирован" << endl;
		S = (x >> 4) & 0xF; // число S занимает 3 разряда (4^3-1=15) начиная с 4
		cout << dec << "Код системной области = " << S << endl; // вывод в десятичном виде S

		G = (x >> 8) & 0xFF;
		cout << dec << "Идентификатор группы пользователя = " << G << endl;
	}
	else
		cout << "Введено некорректное значение" << endl;
	return 0;
}
