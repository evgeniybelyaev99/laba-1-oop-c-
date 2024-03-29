// Triangle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Triangle {
	private:
		int a, b, c;
		int P;
		double S;
	public:
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
	int getA() const { return a; }
	void setA(int A) { a = A; }

	int getB() const { return b; }
	void setB(int B) { b = B; }

	int getC() const { return c; }
	void setC(int C) { c = C; }
	
	int getPerim() const { return P; }
//	void setPerim(int perimeter) { P = perimeter; }

	double getArea() const { return S;}
//	void setArea(double area) { S = area;}
	};

	ostream& operator<<(ostream &out, const Triangle &figur)
	{
		out << "Стороны треугольника: " << endl;
		out << "a=" << figur.getA() << " b=" << figur.getB() << " c=" << figur.getC() << endl;
		out << "Периметр треугольника = " << figur.getPerim()<<endl<< "Площадь треугольника = " << figur.getArea() << endl;
		return out;
	}
	ostream& operator<<(ostream &out, Triangle *figur)
	{
		out << "Стороны треугольника: " << endl;
		out << "a=" << figur->getA() << " b=" << figur->getB() << " c=" << figur->getC() << endl;
		out << "Периметр треугольника = " << figur->getPerim() << endl << "Площадь треугольника = " << figur->getArea() << endl;
		return out;
	}

	void Input(Triangle& figur)
	{
		cout << "Введите стороны треугольника: " << endl;
		int A, B, C;
		cin >> A >> B >> C;
		figur = Triangle{A, B, C};
	}
	void Input(Triangle*& figur) 
	{
		cout << "Введите стороны треугольника: " << endl;
		int A, B, C;
		cin >> A >> B >> C;
		figur = new Triangle{ A, B, C };
	}
	void Output(Triangle& figur)
	{
		cout << figur << endl;
	}
	
	void Output(Triangle*& figur)
	{
		cout << figur << endl;
	}

	int main()
	{
		setlocale(LC_ALL, "Rus");
		Triangle figur = Triangle();
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


