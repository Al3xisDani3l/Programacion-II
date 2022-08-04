// T1 - Termino polinomio.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

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

	T* _arr;

	size_t _size;
	size_t _cantidadElementos;

	T* copyArray(T _old[], size_t sizeOld, size_t sizenew) {

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
ostream& operator <<(ostream& out, MyArray<T>* _in) {

	for (size_t i = 0; i < _in->GetSize(); i++)
	{
		out << _in->Get(i) << " ";
	}
	return out;
}




#pragma endregion


struct Termino
{
public:
	Termino();
	void Set(float co, float ex);
	Termino(float co, float ex);
	ostream& Print(ostream& out, char coeficiente = 'x');
	~Termino();
	float coeficiente;
	float exponente;
private:
	
};



Termino::Termino()
{
	coeficiente = 0;
	exponente = 0;
}

void Termino::Set(float co, float ex)
{
	coeficiente = co;
	exponente = ex;
}

Termino::Termino(float co, float ex)
{
	coeficiente = co;
	exponente = ex;
}

ostream& Termino::Print(ostream& out, char co)
{

	out << coeficiente << co << "^" << exponente;
	return out;
	// TODO: Insertar una instrucción "return" aquí
}

Termino::~Termino()
{
}

ostream& operator <<(ostream& out,Termino t) {
	
	out << t.coeficiente << "x"<< "^" << t.exponente;
	return out;
}

/// <summary>
/// Sobrecargamos la entrada de la consola para que pueda leer terminos de polinomios 
/// </summary>
/// <param name="_in"></param>
/// <param name="t"></param>
/// <returns></returns>
istream& operator >>(istream& _in, Termino& t) {

	float co;
	float ex;
	char charco;
	char expo;

	cin >> co >> charco >> expo >> ex;

	t.coeficiente = co;
	t.exponente = ex;
	
	return cin;

}

int main()
{
	//Clase que se encarga de llevar el control de los terminos introducidos.
	MyArray<Termino>* polinomio = new MyArray<Termino>();


	int tamano;

	
	
	cout << endl << "Cuantos terminos contendra el polinomio : ";
	cin >> tamano;

	cout << endl << endl;

	//Pedimos al usuario que introdusca un polinomio con el formato <co>x^<ex>
	//ejemplo 12x^3
	//acepta numeros negativos
	//ejemplo -12x^5
	for (size_t i = 0; i <tamano; i++)
	{
		Termino temp;

		cout<<endl << "Termino " << i + 1 << ": ";
		cin>>temp;

		polinomio->Add(temp);
		

		
	}
	 
	//imprimimos en la consola
	cout << endl << endl << "f(x)= ";
	for (size_t i = 0; i < polinomio->GetSize(); i++)
	{
		Termino temp = polinomio->Get(i);
		if (i == 0)
		{
			cout << temp;
		}		
		else
		{
			if (temp.coeficiente >= 0)
			{
				cout << " + " << temp;
			}
			else
			{
				cout << "  " << temp;
			}
	
		}

	}
	

  
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
