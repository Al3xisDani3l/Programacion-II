// Proyecto Final Equipo 5
// Alexis Daniel Hernandez Gamez  - 180263
// Genesis Erizel Arteaga Rangel - 182129
// Francisco Antonio Hernandez Mena - 180233

#pragma once
#ifndef POINT_H
#define POINT_H

#include "math.h"
#include <iostream>
#include "Bubble.h"
using namespace std;

class Point {
	float* Values; //Máximo 100 puntos por punto
	int Size;
	int Class;

public:
	friend class BubbleSort;

	Point(float* v, int Size, int c) {
		this->Values = v;
		this->Size = Size;
		this->Class = c;
	}

	Point() {
		this->Size = 0;
		this->Class = -1;
		this->Values = new float[4];
	}

	~Point() {
		delete[] Values;
		cout << "~Point()" << endl;
	}


	void Print() {
		cout << "Size: " << Size << "   Values: ";
		for (int i = 0; i < Size; i++)
			cout << Values[i] << ", ";
		cout << "\t" << "Class: " << Class;
		cout << endl;
	}

	int getSize() const {
		return Size;
	}

	void SetClass(int clase) {
		Class = clase;
	}

	float getValue(int index) const {
		if (index >= 0 && index < this->Size)
		{
			return Values[index];
		}
		throw "Indice fuera de rango";
	}

	int getClass() {
		return Class;
	}

	

	float operator -(const Point* p) {
		float sum = 0;
		for (int i = 0; i < p->getSize(); i++) {
			sum += pow(p->getValue(i) - this->getValue(i), 2);
		}
		return sqrt(sum);
	}


};



//float operator -(const Point& p1, const Point * p2) {
//
//	float sum = 0;
//	for (int i = 0; i < p1.getSize(); i++) {
//		sum += pow(p1.getValue(i) - p2->getValue(i), 2);
//	}
//	return sqrt(sum);
//}



#endif