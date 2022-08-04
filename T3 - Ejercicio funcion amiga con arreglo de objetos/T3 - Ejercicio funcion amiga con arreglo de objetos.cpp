// T3 - Ejercicio funcion amiga con arreglo de objetos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "MyArray.h"
using namespace std;


class Producto
{
public:
	static int cId;

	Producto() {
		Producto::cId++;
		idP = Producto::cId;
		name = "Unamed";
		this->cantidad = 0;
		this->precio = 0;
	}
	Producto(string nombre, int cantidad, double precio) {
		
		Producto::cId++;
		idP = Producto::cId;
		name = nombre;
		this->cantidad = cantidad;
		this->precio = precio;
	}

	friend double precioTotal(Producto& pr);

	
	

	~Producto() {

	}

private:
	
	int idP;
	string name;
	int cantidad;
	double precio;
};

double precioTotal(Producto& pr) {

	cout << endl << "Producto Id: " << pr.idP;
	cout <<endl <<"Nombre: " << pr.name;
	cout << endl << "Cantidad de productos comprados: "<<pr.cantidad;
	cout << endl << "Precio por unidad: " << pr.precio<<"$";
	cout << endl << "subtotal de las unidades: " << pr.cantidad * pr.precio << "$";

	return pr.cantidad* pr.precio;
}



int Producto::cId = 0;

int main()
{ 
	int cantidadProductos = 0;

	//Variables para cada producto;

	string nombrep;
	int cantidadp;
	double preciop;

	//sumatoria de los productos

	double totalp = 0;

	MyArray<Producto>* productos = new MyArray<Producto>();

	cout << endl << "Cuantos productos desea llevar: ";
	cin >> cantidadProductos;

	//ajustamos el tamaño del array dinamico para no estarlo ajustando cada vez
	productos->Resize(cantidadProductos);



	for (size_t i = 0; i < cantidadProductos; i++)
	{
		cout <<endl<< endl << endl << "Producto " << i + 1 << ":" << endl<<endl;
		cout << "Nombre: ";
		cin >> nombrep;
		cout << endl << "Cantidad: ";
		cin >> cantidadp;
		cout<<endl<< "Precio por unidad: ";
		cin >> preciop;

		productos->Add(Producto(nombrep, cantidadp,preciop));

		system("cls");
	}

	cout << endl << endl << "-----Informacion de la venta-----" << endl << endl;


	for (size_t i = 0; i < cantidadProductos; i++)
	{
		Producto temp = productos->Get(i);

		totalp += precioTotal(temp);
		cout << endl << endl;

	}

	cout << endl << "                Total: " << totalp << "$" << endl<<endl;



	
   
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
