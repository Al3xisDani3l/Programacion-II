// Tarea 8 - Factura.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class Factura
{
public:
	Factura():Factura("","",0,0) {

	}

	Factura(string nombreArticulo, string descripcion, float cantidadArticulos, float precioUnitario) {
		NombrePieza(nombreArticulo);
		Descripcion(descripcion);
		CantidadArticulos(cantidadArticulos);
		PrecioUnitario(precioUnitario);

	}

	void NombrePieza(string nombre) {

		if (!nombre.empty())
		{
			_numeroPieza = nombre;
		}
		else
		{
			_numeroPieza = "";
		}
		
	}

	string NombrePieza() {
		return _numeroPieza;
	}

	void Descripcion(string descripcion) {
		if (!descripcion.empty())
		{
			_descripcionPieza = descripcion;
		}
		else
		{
			_descripcionPieza = "";
		}
	}


	void CantidadArticulos(float cantidad) {
		if (cantidad < 0)
		{
			cout<<endl << "La cantidad de articulos no puede ser negativa, se inicizalizara en ceros"<<endl;
			_cantidadArticulos = 0;
		}
		else
		{
			_cantidadArticulos = cantidad;
		}
	}


	float CantidadArticulos() {
		return _cantidadArticulos;
	}


	void PrecioUnitario(float precio) {
		if (precio < 0)
		{
			cout << endl << "El precion no puede ser negativa, se inicizalizara en ceros" << endl;
			_precionUnitario = 0;
		}
		else
		{
			_precionUnitario = precio;
		}
	}

	float PrecioUnitario() {
		return _precionUnitario;
	}

	float Total() {
		_cantidadArticulos * _precionUnitario;
	}

private:

	string _numeroPieza;
	string _descripcionPieza;
	float  _cantidadArticulos;
	float _precionUnitario;


};



int main()
{
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
