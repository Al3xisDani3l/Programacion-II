#pragma once
#include <iostream>
class DesviacionEstandar
{
	float datos[100];
	float promedio;
	float sumatoria;
	int index;
	


	float Promedio();

public:


	void AddElement(float x) {
		datos[index] = x;
		index++;
	}

	void Print(std::ostream & stream);

	float Calculate();

	DesviacionEstandar();
	DesviacionEstandar(float datosIn[], int tamano);
	
};

