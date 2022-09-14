#include <iostream>
#include <math.h>
#include <fstream>
#include <ctime>
#include <string>
#include <iomanip>
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
	int len = 50;
	for (int i = 0; i < 13; i++) {
		cout << i << " ";
		if (i == 0) {
			cout << setw(17);
			for (int j = 0; j < 30; j++) {
				cout << "=";
			}
		}
		else if (1 <= i && i <= 7) {
			for (int j = 0; j < 16; j++) {
				cout << " *";
			}
			for (int j = 0; j < 34; j++) {
				cout << "=";
			}
		}
		else {
			for (int j = 0; j < len; j++) {
				cout << "=";
			}
		}
		cout << "\n";
	}
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "RUSSIAN");
	//dz41();
	//dz42();
	//dz43();
	dz44();
}
