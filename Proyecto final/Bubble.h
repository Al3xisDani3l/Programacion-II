// Proyecto Final Equipo 5
// Alexis Daniel Hernandez Gamez  - 180263
// Genesis Erizel Arteaga Rangel - 182129
// Francisco Antonio Hernandez Mena - 180233



#ifndef BUBBLE_H
#define BUBBLE_H
#include "Point.h"
#include "Sorting.h"


#include <iostream>
using namespace std;


//#include "Sorting.h"

//class Bubble : public Sorting {
class Bubble: public Sorting {
	
	int* Classes;
	
public:
	Bubble(float* arr,
		int* Classes,
		int Size):Sorting(arr,Size) {

		this->_arr = arr;
		this->Classes = Classes;
		this->_size = Size;
	}


	void SortAsc() override {
		float tmp;
		int tmpClass;
		bool Sorted;
		
		do {
			Sorted = true;

			//_size - 1 para no desbordar los indices
			for (int i = 0; i < _size - 1; i++) {
				
				
				//si el elemento siguiente de i es mayor invertimos sus posiciones

				if (_arr[i] > _arr[i + 1]) {

					//ordenamos las distancias
					//guardamos temporalmente el dato de _arr[i] para que no se pierda en la asignacion
					tmp = _arr[i];
					_arr[i] = _arr[i + 1];
					_arr[i + 1] = tmp;

					//ordenamos las clases de los puntos
					tmpClass = Classes[i];
					Classes[i] = Classes[i + 1];
					Classes[i + 1] = tmpClass;

					Sorted = false;
				}
			}
		} while (!Sorted);


		cout << "Impresion de las distancias ordenadas" << endl;
		cout << "Index \t Distance \t Classes" << endl;

		//imprimimos las distancias con sus respectivas clases
		for (int i = 0; i < _size; i++) {
			cout << i << "\t\t" << _arr[i] << "\t\t" << Classes[i] << endl;
		}
	}
};
#endif