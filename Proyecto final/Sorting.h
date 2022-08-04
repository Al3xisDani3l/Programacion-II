// Proyecto Final Equipo 5
// Alexis Daniel Hernandez Gamez  - 180263
// Genesis Erizel Arteaga Rangel - 182129
// Francisco Antonio Hernandez Mena - 180233

#include <iostream>
#include <random>

using namespace std;

/// <summary>
/// Definicion de la clase base sorting, contiene los metodos para ordenar y mostrar un array
/// </summary>

class Sorting
{
public:
	Sorting(float * arr, int size) {

		_arr = arr;
		_size = size;
	}
	~Sorting() {
		delete[] _arr;
	}

	virtual void SortAsc() {
		cout << "\nEstoy dentro de la funcion \"SortAsc\"\n";
	}

	void Print() {

		for (size_t i = 0; i < _size; i++)
		{
			cout << endl << "Valor " << i + 1 << ": " << _arr[i] << endl;
		}
	}






protected:

	float * _arr;
	int _size;

private:




};
