﻿
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus"); // просим пользователя ввести данные
	cout << "Введите данные в нужном порядке: идентификатор группы пользователя,код системы, которая загружается для пользователя,признак привилегированного пользователя" << endl;
	int G, S, P;
	unsigned short x = 0;
	cin >> G >> S >> P ; // вводим числа в нужной последовательности
	if ((G >= 0 && G <= 255) && (S >= 0 && S <= 15) && (P >= 0 && P <= 1)) { // проверяем введённые данные
		unsigned short x = P << 3 | S << 4 | G << 8 ; // формируем шестнадцатиричное число х
		cout << hex << x; // вывод полученного значения
	}
	else
		cout << "Введите значения заново" << endl; // при несоблюдении условий просим заново ввести значения
	return 0;
}