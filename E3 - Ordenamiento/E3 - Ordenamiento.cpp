// E3 - Ordenamiento.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Alexis Daniel Hernandez Gamez - 180263

#include <iostream>
#include <random>

using namespace std;

/// <summary>
/// Definicion de la clase base sorting, contiene los metodos para ordenar y mostrar un array
/// </summary>
class Sorting
{
public:
	Sorting(int* arr, int size) {

		_arr = arr;
		tamano = size;
	}
	~Sorting() {
		delete[] _arr;
	}

	virtual void SortAsc() {
		cout << "\nEstoy dentro de la funcion \"SortAsc\"\n";
	}

    void Print() {

		for (size_t i = 0; i < tamano; i++)
		{
			cout << endl << "Valor " << i + 1 << ": " << _arr[i] << endl;
		}
	}






protected:

	int* _arr;
	int tamano;

private:




};

class BubbleSort:public Sorting
{
public:
	BubbleSort(int* arr, int size):Sorting(arr,size){}
	
     void SortAsc() override {
		
		 int tmpClass;
		 bool Sorted;

		 //mostramos un mensaje indicando que se esta realizando el ordenamientio de burbuja
		 cout << "\n---Ordenamiento de burbuja---\n";

		 do {
			 Sorted = true;

			 for (int i = 0; i < tamano - 1; i++) {
				 if (_arr[i] > _arr[i + 1]) {			

					 tmpClass = _arr[i];
					 _arr[i] = _arr[i + 1];
					 _arr[i + 1] = tmpClass;

					 Sorted = false;
				 }
			 }
		 } while (!Sorted);

	}


private:

};

class InsertionSort: public Sorting
{
public:
	InsertionSort(int* arr, int size):Sorting(arr,size){}

	void SortAsc() override
	{
		//mostramos un mensaje indicando que se esta realizando el inserction sort
		cout << "\n---Ordenamiento de inserccion---\n";

		int i, key, j;
		for (i = 1; i < tamano; i++)
		{
			key = _arr[i];
			j = i - 1;

		
			while (j >= 0 && _arr[j] > key)
			{
				_arr[j + 1] = _arr[j];
				j = j - 1;
			}
			_arr[j + 1] = key;
		}


	}

private:

};

/// <summary>
/// recibe instancias y clases hijas de la clase sorting
/// </summary>
/// <param name="alg">clase ordenadora</param>
void SortData(Sorting* alg) {

	alg->SortAsc();
	alg->Print();


}



int main()
{
	//se utiliza para poner la semilla en base a la hora del computador
	srand(time(NULL));

	//tamano dinamico de la clase
	int size = 100;
	//creamos 2 arreglos distintos para cada clase ordenadora
	int* arr1 = new int[size];
	int* arr2 = new int[size];

	for (size_t i = 0; i < size; i++)
	{

		//para cada array asignamos un numero entre el 0 al 100 incluyendo el 100
		arr1[i] = rand() % 101;
		arr2[i] = rand() % 101;

	}



	
	//instanciamos los objetos
	BubbleSort *obj1 = new BubbleSort(arr1, size);
	InsertionSort *obj2 = new InsertionSort(arr2, size);


	//primera llamada 
	SortData(obj1);
	//segunda llamada
	SortData(obj2);
	
	//eliminamos los objetos que ocuparon memoria dinamica
	delete obj1;
	delete obj2;
	/*delete[] arr1;
	delete[] arr2;*/

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
