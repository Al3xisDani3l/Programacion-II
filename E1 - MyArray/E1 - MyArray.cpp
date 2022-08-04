// E1 - MyArray.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Examen programacion II: Parcial 1
//Alexis Daniel Hernandez Gamez
//Matricula: 180263
//Programado el dia 03/03/2021



#include <iostream>
#include <time.h>


using namespace std;

#pragma region MyArray Implementacion
//Array dinamico que ajusta su tamaño de manera automatica.
template<typename T> class MyArray
{
public:


	

	MyArray() {
		_arr = NULL;
		_cantidadElementos = 0;
		_size = 0;

	}

	MyArray(size_t size) {

		_arr = new T[size];
		_size = size;
		_cantidadElementos = 0;
	}
	void Add(T element) {

		if (_cantidadElementos < _size)
		{
			this->_arr[_cantidadElementos] = element;
			_cantidadElementos++;
		
		}
		else
		{
			_arr = copyArray(_arr, _size, _size + 5);
			_arr[_cantidadElementos] = element;
			_cantidadElementos++;

			
		}
		
	}
	void clear() {
		delete[] _arr;

		_arr = new T[_size];

		_cantidadElementos = 0;
	}
	bool Resize(size_t newsize) {
	
		if (newsize > _size)
		{
			_arr = copyArray(_arr, _size, newsize);
			return true;
		}
		else
		{
			return false;
		}	
	}

	size_t GetSize() {

		return _cantidadElementos;
	}

	size_t GetSizeMax() {
		return _size;
	}

	T Get(size_t index) {

		if (index < _cantidadElementos)
		{
			return _arr[index];
		}
		else
		{
			return NULL;
		}
	}

	bool Set(size_t index, T newElement) {

		if (index <= _cantidadElementos)
		{
			_arr[index] = newElement;
			return true;
		}
		else
		{
			return false;
		}

	}

	void Print(ostream& out) {
		for (size_t i = 0; i < _cantidadElementos; i++)
		{
			out << _arr[i] << endl;
		}
  }

	


	~MyArray() {
		if (_arr != NULL)
		{
			delete[] _arr;
		}
		_size = NULL;
	}

	

private:
	
	T *_arr;

	size_t _size;
	size_t _cantidadElementos;

	T* copyArray(T _old[],size_t sizeOld, size_t sizenew) {

		T* temp = new T[sizenew];
		
		for (size_t i = 0; i < sizeOld; i++)
		{
			temp[i] = _old[i];
		}
		_size = sizenew;
		return temp;

	}

};

template<typename T>
ostream& operator <<(ostream& out, MyArray<T>& _in) {

	for (size_t i = 0; i <_in.GetSize(); i++)
	{
		out << _in.Get(i) << " ";
	}
	return out;
}




#pragma endregion


int main()
{
	//Iniciamos con una nueva semilla
	srand(time(NULL));


	//instanciamos el objeto
	MyArray<int>* my = new MyArray<int>();

	int tamanoNuevo;
	int valorN;
	size_t index;

	bool aproved = false;
	
	
	//Agregamos 5 numeros de manera aleatoria del 0 al 100;
	//este es un array inteligente que ajustara su tamaño en dado caso de que se exceda la capacidad maxima actual
	for (size_t i = 0; i <5; i++)
	{
		my->Add(rand()%100);
	}

	std::cout << endl << "Elementos: " << *my << endl << endl;

	system("pause");

	do
	{

		system("cls");
		cout << "Introduce la nueva capacidad del array: ";
		cin >> tamanoNuevo;
		aproved = my->Resize(tamanoNuevo);
		if (aproved)
		{
			cout << endl << "Capacidad aumentada con exito!" <<endl<<"Capacidad actual: "<<my->GetSizeMax() <<endl << endl;;
		}
		else
		{
			cout << "La capacidad no pudo ser modificada, verifique que sea una nueva capacidad mayor a la actual"<<endl;
		}
		system("pause");

	} while (!aproved);

	aproved = false;



	do
	{
		

		cout <<endl <<"Indice a cambiar: ";
		cin >> index;

		aproved = index < my->GetSize();

		
		if (!aproved)
		{
			cout << endl << "El indice debe de estar entre 0 y " << my->GetSize() - 1<<endl;
			system("pause");
			system("cls");
		}

	} while (!aproved);
	
	
	cout << endl << "Valor actual del indice " << index << ": " << my->Get(index) << ", Actualizar por: ";
	cin >> valorN;

	my->Set(index, valorN);

	cout << "valor actualizado con exito : " << my->Get(index)<<endl;

	system("pause");

	cout << endl << "\t\t<<<Datos del array>>>" << endl<<endl << "Cantidad de elementos introducidos: " << my->GetSize() << endl;
	cout << "Capacidad maxima actual: " << my->GetSizeMax();

	 

	std::cout << endl << "Elementos: " << *my << endl << endl;

	system("pause");

	delete my;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
