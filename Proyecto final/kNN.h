// Proyecto Final Equipo 5
// Alexis Daniel Hernandez Gamez  - 180263
// Genesis Erizel Arteaga Rangel - 182129
// Francisco Antonio Hernandez Mena - 180233

#ifndef KNN_H
#define KNN_H

#include "dataset.h"


#include "Bubble.h"

#define SIZE 3

class kNN {

	Dataset* _dataset;
	int kMasCercanos;
	int Classes;
	Sorting* ordenamiento;

	float* _distancias;
	int* _clases;

	int* typeClases;
	int _cantidadClases;


	


public:
	//*d   		es un puntero a un objeto dinámico de la clase dataset
	//k    		es el número de las clases que se van a considerar como las más cercanas al punto a evaluar
	//Classes	es el número de clases que hay en los datos (dataset). En el dataset que le voy a pasar existen 3 clases.
	//*b		es un puntero a un objeto dinámico del algoritmo de ordenamiento
	kNN(Dataset* dataset, int k, int cantidadClases) {

		_cantidadClases = cantidadClases;
		_distancias = new float[dataset->getSize()];
		_clases = new int[dataset->getSize()];

		typeClases = new int[cantidadClases];

		for (size_t i = 0; i < cantidadClases; i++)
		{
			typeClases[i] = 0;
		}

		this->_dataset = dataset;
		this->kMasCercanos = k;
		this->ordenamiento = ordenamiento;

	}

	~kNN() {
		delete ordenamiento;
		delete _dataset;
		delete[] typeClases;
	}


	//Esta función sería el programa principal, el cual nos dará la clase que le corresponde a un nuevo punto
	int getClass(Point* p) {

		int max = 0;
		//El parámetro que se recibe representa el punto que se va a clasificiar de acuerdo a las k distancias más cercanas
		//1. Cargar los arreglos de distancias y clases de cada punto con respecto a *p que se recibe como parámetro en esta función

		for (size_t i = 0; i < _dataset->getSize(); i++)
		{
			_distancias[i] = *p - _dataset->getPoint(i);
			_clases[i] = _dataset->getClass(i);
		}
		//2. Utilizar *b recibido en el constructor para ordenar el vector de distancias.
		ordenamiento = new Bubble(_distancias, _clases, _dataset->getSize());

		ordenamiento->SortAsc();

		//3. Contar el número de veces que aparece cada una de las clases en los primeros k vecinos más cercanos, es decir, los primeros k elementos del arreglo
		for (size_t i = 0; i < kMasCercanos; i++)
		{
			typeClases[_clases[i]]++;

		}

		//4. retornar el número de la clase que apareció más veces en los k vecinos más cercanos.
		int winer = 0;
		for (size_t i = 0; i < _cantidadClases; i++)
		{
			if (max < typeClases[i])
			{
				winer = i;
				max = typeClases[i];
			}
		}



		return winer;







	}
};

#endif
