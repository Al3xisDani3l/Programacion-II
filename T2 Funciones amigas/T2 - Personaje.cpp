// T2 - Personaje.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;
class Personaje
{

public:
	Personaje(int a, int d) {
		ataque = a;
		defensa = d;

	}

	void MostrarDatos() {
		cout << "Ataque = " << ataque << endl;
		cout << "Defenza = " << defensa << endl;
	}

	friend void Modificar(Personaje & p,int a ,int d);

private:
	int ataque;
	int defensa;
};

void Modificar(Personaje& p, int a, int d)
{
	p.ataque = a;

	p.defensa = d;
}

int main()
{
	Personaje principal(100, 90);

	principal.MostrarDatos();

	Modificar(principal, 50, 40);
	principal.MostrarDatos();

   
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln


