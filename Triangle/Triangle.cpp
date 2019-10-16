// Triangle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Triangle {
	public:
	int a, b, c;
	Triangle() 
	{
		a = 3, b = 4, c = 5;
	}
	Triangle(int side1, int side2, int side3) 
	{
		if (side1 < side2 + side3 && side2 < side1 + side3 && side3 < side1 + side2)
		{
			a = side1, b = side2, c = side3;
		}
	}
	int perimeter() 
	{
		P = a + b + c;
		
		return P;
	}
	double area() 
	{
		double p = (a + b + c) / 2.0;
		S = sqrt(p*(p - a)*(p - b)*(p - c));
		
		return S;
	}
	int getPerim() const { return P; }
	void setPerim(int perimeter) { P = perimeter; }

	double getArea() const { return S;}
	void setArea(double area) { S = area;}
	
	private:
		int P;
		double S;
};

	ostream& operator<<(ostream &out, const Triangle &figur)
	{
		out << "Perimeter of a triangle = " << figur.getPerim()<<endl<< "Area of a triangle = " << figur.getArea() << endl;
		return out;
	}
	ostream& operator<<(ostream &out, Triangle *figur)
	{
		out << "Perimeter of a triangle = " << figur->getPerim() << endl << "Area of a triangle = " << figur->getArea() << endl;
		return out;
	}

	void Input(Triangle& figur) {
		cout << "Введите стороны треугольника: " << endl;
		int A, B, C;
		cin >> A >> B >> C;
		figur = Triangle{A, B, C};
	}
	void Output(Triangle& figur) {
		cout << "Стороны треугольника: " << endl;
		cout << "a=" << figur.a << " b=" << figur.b << " c=" << figur.c << endl;
		cout << figur << endl;
		
	}
	void Input(Triangle*& figur) {
		cout << "Введите стороны треугольника: " << endl;
		int A, B, C;
		cin >> A >> B >> C;
		figur = new Triangle{ A, B, C };
	}
	void Output(Triangle*& figur) {
		cout << "Стороны треугольника: " << endl;
		cout << "a=" << figur->a << " b=" << figur->b << " c=" << figur->c << endl;
		cout << figur << endl;

	}

	int main()
	{
		setlocale(LC_ALL, "Rus");
		Triangle figur = Triangle();
//		Triangle figur;
//		Input(figur);
		figur.perimeter();
		figur.area();
		Output(figur);
		
		Triangle *figur1 = new Triangle;
		Input(figur1);
		figur1->perimeter();
		figur1->area();
		Output(figur1);
		delete figur1;
	}


