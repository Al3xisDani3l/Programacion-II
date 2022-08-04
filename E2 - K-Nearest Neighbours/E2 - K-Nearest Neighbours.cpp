// E2 - K-Nearest Neighbours.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;


#pragma region Array Class implementation

template<typename T>
class MyArray
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
	virtual void Add(T element) {

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
	virtual void clear() {
		delete[] _arr;

		_arr = new T[_size];

		_cantidadElementos = 0;
	}
	virtual bool Resize(size_t newsize) {

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



#pragma endregion


class Point
{
public:
	Point() {
		w = 0;
		x= 0;
		y= 0;
		z= 0;
		p= -1;
	}
	Point(float w,float x,float y,float z) {
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
		this->p = p;
	}
		~Point();

	float GetX() { return this->x; }
	float GetY() { return this->y; }
	float GetW() { return this->w; }
	float GetZ() { return this->z; }
	int GetP() { return this->p; }

	void SetW(float v) { this->w = v; }
	void SetX(float v) { this->x = v; }
	void SetY(float v) { this->y = v; }
	void SetZ(float v) { this->z = v; }
	void SetP(int v) { this->p = v; }

	

private:
	float w;
	float x;
	float y;
	float z;
	int   p;

};

float operator -( Point& t,  Point& pd) {

	float sum = 0;
	float result = 0;

	sum += powf((t.GetW() -pd.GetW()), 2);
	sum += powf((t.GetX()- pd.GetX()), 2);
	sum += powf((t.GetY()- pd.GetY()), 2);
	sum += powf((t.GetZ()- pd.GetZ()), 2);

	result = powf(sum, 0.5);

	return result;

}

ostream& operator << (ostream& os, Point* p) {

	os << "(" + to_string(p->GetW()) + ","
		+ to_string(p->GetX()) + ","
		+ to_string(p->GetY()) + ","
		+ to_string(p->GetZ()) + ")";

	return os;
}

ostream& operator << (ostream& os, Point& p) {

	os << "(" + to_string(p.GetW()) + ","
		+ to_string(p.GetX()) + ","
		+ to_string(p.GetY()) + ","
		+ to_string(p.GetZ()) + ")";

	return os;
}

class DataSet
{
public:
	DataSet() {
		_sizeEsperado = 5;
		_size = 0;
	}
	DataSet(size_t size) {

		_sizeEsperado = size;
		_size = 0;
	}
	~DataSet() {
		delete[] points;
	}

	void Add(Point* p) {

		points[_size] = p;

		_size++;	
	}

	Point* Get(size_t index) {
		if (index < _size)
		{
			return points[index];

		}
		else
		{
			cout << "Indice fuera de los limites";
		}
	}

	int GetSize() {

		return _size;
	}

	

private:
	Point* points[100];
	int _size;
	int _sizeEsperado;
};


ostream& operator <<(ostream& os, DataSet* datos) {

	for (size_t i = 0; i < datos->GetSize(); i++)
	{
		os << "Indice : " << i << endl << datos->Get(i) << endl<<endl;

	}
	return os;
}


int main()
{



	//Iniciamos inicializando 5 puntos dinamicamente

	Point* p1 = new Point(1, 2, 3, 4);

	Point* p2 = new Point(2, 3, 4, 5);

	Point* p3 = new Point(7, 9, 11, 17);

	Point* p4 = new Point(21, 4, 8, 9);

	Point* p5 = new Point(7, 8, 33, 12);


	//Los mostramos en pantalla

	cout << endl << "------Puntos-----" << endl;

	cout << endl << p1 << endl;
	cout << endl << p2 << endl;
	cout << endl << p3 << endl;
	cout << endl << p4 << endl;
	cout << endl << p5 << endl;

	//inicializamos el data set
	DataSet* Points = new DataSet();


	//Agregamos los puntos al data set;
	Points->Add(p1);
	Points->Add(p2);
	Points->Add(p3);
	Points->Add(p4);
	Points->Add(p5);



	//Mostramos los puntos en el data set;
	cout << endl << "------Puntos en el DataSet-----"<<endl<<endl;
	cout << Points;

	Point* Mul = new Point(15, 45, 78, 32);


	cout << endl << "------Distancias euclidianas-----" << endl << endl;
	

	for (size_t i = 0; i < Points->GetSize(); i++)
	{

		float value = *Points->Get(i) - *Mul;

		cout<<endl << "Distancia " << i + 1 << ": " << value<<endl;

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
