﻿#include<iostream>
using namespace std;
 

class Point
{
	double x;
	double y;
public: 
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define struct_point

void main()
{
	setlocale(LC_ALL, "");

#ifdef struct_point

	int a;   // объявление переменной 'a' типа 'int'.
	Point A; // объявление переменной 'А' типа 'Point'.
	         // Создание объекта 'А' структуры 'Point'.
	         // Создание экземпляра 'А' структуры 'Point'.
	         // 'A' is instance of struct 'Point'
	         // Instantiate - создать объект.
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // struct_point

	Point A;
	A.get_x(2);
	A.get_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

}

