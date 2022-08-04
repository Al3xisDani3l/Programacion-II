// Ejercicio 4 (Vehículo, coche, moto).cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;


class Vehiculo
{
public:
	Vehiculo() { cout << "Esto es un vehiculo cualquiera...\n"; }

	void desplazar() { cout << "Moviendose..."; }

private:
	void hola() { cout << "hola"; }

protected:
	int numero;
};

class Coche: public Vehiculo
{
public:
	Coche() { cout << "Esto es un coche...\n"; }
	void desplazar() { cout << "Yo me desplazo de una manera distinta a la clase base\n"; }
	int numRuedas;

private:

};

class Moto: public Coche
{
public:
	Moto() { cout << "Esto es una moto...\n"; }
	int numRuedas;

private:

};




int main()
{

	Coche miMoto;
	miMoto.desplazar();

	system("pause>nul");
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
