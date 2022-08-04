#pragma once

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
	/*	else
		{
			return (T)NULL;
		}*/
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
ostream& operator <<(ostream& out, MyArray<T>& _in) {

	for (size_t i = 0; i < _in.GetSize(); i++)
	{
		out << _in.Get(i) << " ";
	}
	return out;
}




#pragma endregion