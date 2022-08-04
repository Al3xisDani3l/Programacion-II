#include "DesviacionEstandar.h"
#include <math.h>



DesviacionEstandar::DesviacionEstandar(float datosIn[], int tamano) {
	 promedio = 0;
	 sumatoria = 0;
	
	index = 0;
	for (size_t i = 0; i < tamano; i++)
	{
		AddElement(datosIn[i]);
	}

}

DesviacionEstandar::DesviacionEstandar() {
	promedio = 0;
	sumatoria = 0;
	index = 0;
}

float DesviacionEstandar::Promedio() {

	float sum = 0;

	float resultado;

	for (size_t i = 0; i < index; i++)
	{
		sum = sum + datos[i];
	}

	resultado = sum / (index);
	return resultado;

}

float DesviacionEstandar::Calculate() {

	float sum = 0;

	float avg = Promedio();

	for (size_t i = 0; i < index; i++)
	{
		float cuadrado = powf(datos[i] - avg, 2);

		sum = sum + cuadrado;
		
	}

	float res1 = sum / index;

	float resultadoF = sqrt(res1);

	return resultadoF;





}

void DesviacionEstandar::Print(std::ostream & stream) {

	for (size_t i = 0; i < index; i++)
	{
		stream << "Dato " << i + 1 << ": " << datos[i] << "\n";
	}

}