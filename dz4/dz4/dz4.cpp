#include <iostream>
#include <math.h>
#include <fstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <strstream>
using namespace std;

void dz41() {
	ofstream dzfile("dz41.txt");
	for (int i = 0; i < 10; i++) {
		dzfile << rand() << "\n";
	}
	dzfile.close();
	ifstream myfile("dz41.txt");
	double x = 0, sum = 0;
	for (int i = 0; i < 10; i++) {
		myfile >> x;
		cout << x << " ";
		sum += x;
	}
	cout << "\n";
	cout << sum << endl;
}


void sign(double x) {
	if (x > 0) {
		cout << 1 << endl;
	}
	else if (x == 0 ) {
		cout << 0 << endl;
	}
	else {
		cout << -1 << endl;
	}
}
void dz42() {
	cout << "Введите число: ";
	double chislo = 0;
	cin >> chislo;
	sign(chislo);
}


void pryam() {
	cout << "Введите стороны прямоугольника: ";
	double a, b;
	cin >> a >> b;
	if (a > 0 && b > 0) {
		cout << "Площадь прямоугольника равна " << a * b << endl;
	}
	else {
		cout << "Прямоугольника с такими сторонами не существует" << endl;
	}
}
void treug() {
	cout << "Введите стороны треугольника: ";
	double x, y, z;
	cin >> x >> y >> z;
	if (x < y + z && y < x + z && z < x + y && x > 0 && y > 0 && z > 0) {
		double p = (x + y + z) / 2;
		cout << "Площадь треугольника равна " << sqrt(p * (p - x) * (p - y) * (p - z)) << endl;
	}
	else {
		cout << "Треугольника с такими сторонами не существует" << endl;
	}
}

void krug() {
	cout << "Введите радиус круга: ";
	double pi = acos(-1.0), r = 0;
	cin >> r;
	if (r > 0) {
		cout << "Площадь круга равна " << pi * r * r << endl;
	}
	else {
		cout << "Круга с таким радиусом не существует" << endl;
	}
}
void dz43() {
	pryam();
	treug();
	krug();
}

void dz44() {
	for (int i = 0; i < 13; i++) {
		if (0 <= i && i <= 6) {
			for (int j = 0; j < 16; j++) {
				cout << " *";
			}
			cout << " ";
			for (int j = 0; j < 34; j++) {
				cout << "=";
			}
		}
		else {
			for (int j = 0; j < 67; j++) {
				cout << "=";
			}
		}
		cout << "\n";
	}
}

void dz46() {
	cout << "Введите римское число: ";
	string x;
	cin >> x;
	int* ch = new int[50];
	for (int i = 0; i < x.length(); i++) {
		if (x[i] == 'I') {
			ch[i] = 1;
		}
		else if (x[i] == 'V') {
			ch[i] = 5;
		}
		else if (x[i] == 'X') {
			ch[i] = 10;
		}
		else if (x[i] == 'L') {
			ch[i] = 50;
		}
		else if (x[i] == 'C') {
			ch[i] = 100;
		}
		else if (x[i] == 'D') {
			ch[i] = 500;
		}
		else if (x[i] == 'M') {
			ch[i] = 1000;
		}
	}
	int maxmest = 0;
	for (int i = x.length() - 2; i >= 0; i--) {
		if (ch[i + 1] > ch[i]) {
			maxmest = ch[i + 1];
			ch[i] = -ch[i];
		}
		else if (ch[i] < maxmest) {
			ch[i] = -ch[i];
		}
		else if (ch[i] >= maxmest) {
			maxmest = ch[i];
		}
	}
	int chislo = 0;
	for (int i = 0; i < x.length(); i++) {
		cout << ch[i] << " ";
		chislo += ch[i];
	}
	cout << '\n';
	cout << chislo << '\n';
}

void dz48() {
	cout << "Введите число, исходную систему счисления и целевую систему счисления: ";
	int ishsh, celsh;
	string x;
	cin >> x >> ishsh >> celsh;
	int i = 0;
	int* ch = new int[50];
	while (x[i] != '\0') {
		if ('0' <= x[i] && x[i] <= '9') {
			ch[i] = (int)x[i] - 48;
		}
		else if ('a' <= x[i] && x[i] <= 'z') {
			ch[i] = (int)x[i] - 87;
		}
		else if ('A' <= x[i] && x[i] <= 'Z') {
			ch[i] = (int)x[i] - 55;
		}
		else {
			cout << "Такого числа не может существовать" << endl;
			return;
		}
		if (ch[i] >= ishsh) {
			cout << "Цифры " << x[i] << " в системе счисления с основанием " << ishsh << " нет" << endl;
			return;
		}
		i++;
	}
	int newx = 0;
	for (int j = 0; j < i; j++) {
		newx += ch[i - 1 - j] * pow(ishsh, j);
	}
	string new2x;
	while (newx > 0) {
		new2x += to_string(newx % celsh);
		newx = newx / celsh;
	}
	int len = new2x.length();
	for (int j = 0; j < len / 2; j++) {
		int perstan = new2x[j], index = len - 1 - j;
		new2x[j] = new2x[index];
		new2x[index] = perstan;
	}
	cout << new2x << endl;
}
int main() {
	srand(10000);
	setlocale(LC_ALL, "ru_RU.UTF-8");
	//dz41();
	//dz42();
	//dz43();
	//dz44();
	dz46();
	//dz48();
	return 0;
}
