﻿
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const int i = 10, j = 10, p = 10, r = 10;
	// M - количество строк, N - количество столбцов
	int a[i][j]; // создаём массив a
	int b[p][r]; // создаём вспомогательный массив b для отображения локальных максимумов

	for (int t = 0; t < i; t++) { // создаём цикл для присваивания значений элементам массива a
		for (int k = 0; k < j; k++) {
			a[t][k] = rand() % 7 + 1;
		}
	}
	for (int t = 0; t < i; t++) { // создаём цикл для присваивания значений элементам массива b
		for (int k = 0; k < j; k++) {
			b[t][k] = 0;
		}
	}
	cout << "Исходная матрица: " << endl;
	for (int t = 0; t < i ; t++) {  // создаём цикл для вывода массива
			for ( int k = 0; k < j ; k++)
				cout << a[t][k] << ' ';
			cout << endl;
		}
	// cout << "a[" << t << "," << k << "]="; cin >> a[t][k]; ручной ввод
	int min = 0;
	for (int t = 0; t < i ; t++) { // создаём цикл для прохода по массиву
		for (int k = 0; k < j ; k++) {

			if (t == 0 && ((0 < k) &&  (k < (j-1))) ) {   // проверка условий 
				if ((a[t][k] < a[t][k - 1]) && (a[t][k] < a[t][k + 1]) && (a[t][k] < a[t + 1][k]) && (a[t][k] < a[t + 1][k + 1]) && (a[t][k] < a[t + 1][k - 1])) {
					min++;
					b[t][k]= a[t][k];
				}
					
            }

				else if (t == (i - 1) && ((0 < k) && (k < (j - 1)))) {
					if ((a[t][k] < a[t][k - 1]) && (a[t][k] < a[t][k + 1]) && (a[t][k] < a[t - 1][k]) && (a[t][k] < a[t - 1][k-1]) && (a[t][k] < a[t - 1][k+1])) {
						min++;
						b[t][k] = a[t][k];
			}
				}

				else if (((0 < t) && (t < (i - 1))) && ((0 < k) && (k < (j - 1)))) {
					if ((a[t][k] < a[t][k - 1]) && (a[t][k] < a[t][k + 1]) && (a[t][k] < a[t - 1][k]) && (a[t][k] < a[t + 1][k]) && (a[t][k] < a[t -1][k- 1]) && (a[t][k] < a[t + 1][k +1]) && (a[t][k] < a[t + 1][k - 1]) && (a[t][k] < a[t - 1][k + 1])) {
						min++;
						b[t][k] = a[t][k];
					}
				}
				else if (k == 0 && ((0 < t) && (t < (i - 1)))) {
					if ((a[t][k] < a[t - 1][k]) && (a[t][k] < a[t + 1][k]) && (a[t][k] < a[t][k + 1]) && (a[t][k] < a[t - 1][k+1]) && (a[t][k] < a[t + 1][k+1])) {
						min++;
						b[t][k] = a[t][k];
					}
				}

				else if (k == (j - 1) && ((0 < t) && (t < (i - 1)))) {
					if ((a[t][k] < a[t - 1][k]) && (a[t][k] < a[t + 1][k]) && (a[t][k] < a[t][k - 1]) && (a[t][k] < a[t - 1][k-1]) && (a[t][k] < a[t + 1][k -1])) {
						min++;
						b[t][k] = a[t][k];
					}
				}

				else if ((k == 0) &&  (t == 0)) {
					if ((a[t][k] < a[t][k+1]) && (a[t][k] < a[t + 1][k]) && (a[t][k] < a[t+1][k +1])) {
						min++;
						b[t][k] = a[t][k];
					}
				}

				else if ((k == (j - 1)) && (t == (i - 1))) {
					if ((a[t][k] < a[t][k - 1]) && (a[t][k] < a[t - 1][k]) && (a[t][k] < a[t - 1][k - 1])) {
						min++;
						b[t][k] = a[t][k];
					}
				}

				else if ((k == (j - 1)) && (t == 0)) {
					if ((a[t][k] < a[t][k - 1]) && (a[t][k] < a[t + 1][k]) && (a[t][k] < a[t + 1][k - 1])) {
						min++;
						b[t][k] = a[t][k];
					}
				}

				else if ((k == 0) && (t == (i - 1))) {
					if ((a[t][k] < a[t][k + 1]) && (a[t][k] < a[t - 1][k]) && (a[t][k] < a[t -1][k + 1])) {
						min++;
						b[t][k] = a[t][k];
					}
				}

				else  {
				k++;
			    }
		}
	}
	cout << "Матрица,отображающая нахождение локальных минимумов: " << endl;
	for (int t = 0; t < i; t++) {  // создаём цикл для вывода массива b
		for (int k = 0; k < j; k++)
			cout << b[t][k] << ' ';
		cout << endl;
	}
	cout << "Количество локальных минимумов в матрице: " << min << endl; 
	int s = 0;
	for (int y = 1,t = 0; t < i; t++) { // создаём цикл для нахождения суммы модулей элементов выше главной диагонали
		for (int k = y ; k < j; k++) {
			s += abs(a[t][k]);
			
		}
		y++;
	}
	cout << "Сумма модулей элементов,стоящих выше главной диагонали: " << s << endl;
	return 0;
}