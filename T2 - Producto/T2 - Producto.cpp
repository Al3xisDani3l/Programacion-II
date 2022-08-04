// T2 - Producto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;



class Registro	
{
public:
	Registro() {
		cost = 0;
	}
	Registro(double cost) {
		this->cost = cost;
	}
	~Registro();

private:
	double cost;
};



class Producto
{
public:
	Producto() {
		nombrep = "";
	}
	Producto(string nombre) {

		nombrep = nombre;
	}	
	

private:

	friend void mostrarDatos(Producto&,Registro&);
	string nombrep;
};

void mostrarDatos(Producto& prod1, Registro& r1) {
	cout << "Nombre del producto: " << prod1.nombrep << endl;
	cout << "Costo del producto: " << r1.cost<<endl;
}

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
