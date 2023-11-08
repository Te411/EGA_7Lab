#include <iostream>
#include <locale.h>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 5; // количество предметов

int main() {
	setlocale(LC_ALL, "rus");
	vector <int> S(N, 0); // набор предметов
	vector <int> C(N); // ценность предмета
	vector <int> W(N); // вес предмета
	int Q = 0; // суммарная ценность всех предметов
	int sumW = 0;
	int Wmax = 0;
	int max = 0;
	int index = 0;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(50, 100);
	Wmax = dis(gen);
	uniform_int_distribution<> diss(2, 50);
	for (int i = 0; i < N; i++) {
		W[i] = diss(gen);
	}
	uniform_int_distribution<> disss(2, 50);
	for (int i = 0; i < N; i++) {
		C[i] = disss(gen);
	}
	cout << "Данные задачи: " << endl;
	cout << "Предмет       Цена       Вес" << endl;
	for (int i = 0; i < N; i++) {
		cout << i + 1 << setw(9)<< "|" << setw(6) << C[i] << setw(5) << "|" << setw(6) << W[i] << endl;
	}
	cout << "Максимальный возможный вес ранца: " << Wmax << endl << endl;

	cout << "Шаг 1" << endl;
	max = 0;
	for (int j = 0; j < S.size(); j++) {
		if (S[j] == 0) {
			if (C[j] > max) {
				max = C[j];
				index = j;
			}
		}
	}
	cout << "Текущая цена ранца: " << Q << endl;
	cout << "Текущий вес ранца: " << sumW << endl;
	if (sumW + W[index] <= Wmax) {
		Q += max;
		sumW += W[index];
		S[index] = 1;
	}
	else {
		cout << "Рюкзак заполнен" << endl;
	}
	cout << "Выбран предмет " << index + 1 << " с ценой " << C[index] << " и весом " << W[index] << endl;
	cout << "Рюкзак заполнен на " << sumW << "/" << Wmax << endl;
	for (int i = 0; i < N - 1; i++) {
		cout << "Шаг " << i + 2 << endl;
		max = 0;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == 0) {
				if (C[j] > max) {
					max = C[j];
					index = j;
				}
			}
		}
		if (sumW + W[index] <= Wmax) {
			cout << "Текущая цена ранца: " << Q << endl;
			cout << "Текущий вес ранца: " << sumW << endl;
			Q += max;
			sumW += W[index];
			S[index] = 1;
		}
		else {
			cout << "Рюкзак заполнен. Предметы больше не влезут" << endl;
			break;
		}
		cout << "Выбран предмет " << index + 1 << " с ценой " << C[index] << " и весом " << W[index] << endl;
		cout << "Рюкзак заполнен на " << sumW << "/" << Wmax << endl;
	}
	cout << endl;
	cout << "Итог" << endl;
	cout << "Были выбраны следующие предметы: ";
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 1) {
			cout <<" " << i + 1;
		}
	}
	cout << endl;
	cout << "Итоговая цена: " << Q << endl;
	cout << "Итоговый вес ранца: " << sumW << endl;
	return 0;
}