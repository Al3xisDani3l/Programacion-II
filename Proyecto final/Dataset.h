// Proyecto Final Equipo 5
// Alexis Daniel Hernandez Gamez  - 180263
// Genesis Erizel Arteaga Rangel - 182129
// Francisco Antonio Hernandez Mena - 180233

#ifndef DATASET_H
#define DATASET_H

#include "Point.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
using namespace std;


class Dataset {
	Point** points;
	int index;
	int size;

	ifstream myfile;
	string filename;
	
public:
	Dataset(string filename) {
		index = 0;
		ifstream cvs(filename);

		string row, tmpnumber;
		int columnas, filas;

		getline(cvs, row);//Leer la primera linea, la que contiene las filas y la cantidad 
		//de cordenadas

		// convertir cadena a un stream para que se comporte como tal
		stringstream _filaInformativa(row);

		//150 4
		getline(_filaInformativa, tmpnumber, ' ');

		//Convertimos la cadena en un numero
		filas = stoi(tmpnumber);

		//instanciamos un array dinamico de 150 tamaño
		points = new Point*[filas];


		//obtenemos la siguiente columa de la primera fila
		getline(_filaInformativa, tmpnumber, ' ');

		//convertimos en un numero entero columnas= 4
		columnas = stoi(tmpnumber);
	
		//segunda linea 
		//5.1 3.5 1.4 0.2 0
		while (getline(cvs, row))
		{
			stringstream dataraw(row);

			float* _data = new float[columnas];
			string _class;
			for (size_t i = 0; i < columnas; i++)
			{
				//obtenemos los numeros separados por espacios
				getline(dataraw, tmpnumber, ' ');

				//convertimos a flotante los 4 puntos que recibimos
				_data[i] = stof(tmpnumber);
			}

			//obtenemos la clase de el punto
			getline(dataraw, _class);

			//instanciamos cada punto
			Point* p = new Point(_data, columnas, stoi(_class));
			//lo agregamos a la lista de puntos
			this->add(p);

		}
		
		
		
	}


	~Dataset() {
		cout << "~Dataset()" << endl;
	}

	void add(Point* p) {
		points[index] = p;
		index++;
	}

	void Print() {
		for (int i = 0; i < size; i++) {
			cout << "Index: " << i << "\t";
			points[i]->Print();

		}

	}

	int getSize() {
		return index;
	}

	Point* getPoint(int index) {
		if (index >= 0 && index < this->index)
		{
			return points[index];

		}
		throw "Indice fuera de rango";
	}

	int  getClass(int index) {
		if (index >= 0 && index < this->index)
		{
			return points[index]->getClass();
		}

		throw "Indice fuera de rango";
	}


};

#endif
