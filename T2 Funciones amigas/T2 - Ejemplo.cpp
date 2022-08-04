// T2 - Ejemplo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class Ejemplo
{
public:
	Ejemplo(int a, int b) {
		attrib1 = a;
		attrib2 = b;
	}
	void Imprime() {
		cout<<endl << "Valor del primer atributo:" << attrib1 << endl;
		cout << "Valor del segundo atributo:" << attrib2<< endl;
	}

	friend int Suma(int n, Ejemplo& e);

private:
	int attrib1;
	int attrib2;

};

int Suma(int n, Ejemplo& e)
{
	return (n + e.attrib1 + e.attrib2);
}

int main()
{

	int resultado;
	Ejemplo ejemplo(2, 5);

	ejemplo.Imprime();

	resultado = Suma(5, ejemplo);

	std::cout <<endl<< "El resultado de la suma es : " << resultado << endl;;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln


