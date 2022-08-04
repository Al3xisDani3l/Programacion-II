// Ejercicio 3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
class Persona
{
public:

	Persona(string, int);
	void mostrar();

private:
	string nombre;
	int edad;
};
class Empleado : public Persona
{
private:
	int dni;
public:
	Empleado(string, int, int);
	void mostrar_d();

};

class Estudiante :public Persona
{
private:
	string carrera;
public:
	Estudiante(string, int, string);
	void show();
};
class Universitario :public Estudiante
{
private:
	int ano;
public:
	Universitario(string, int, string, int);
	void ver();
};
Persona::Persona(string _nombre, int _edad)
{
	nombre = _nombre;
	edad = _edad;
}
void Persona::mostrar()
{
	cout << "mi nombre es:" << nombre << endl;
	cout << "mi edad es:" << edad << endl;
}

Empleado::Empleado(string _nombre, int _edad, int _dni) :Persona(_nombre, _edad)
{
	dni = _dni;
}
void Empleado::mostrar_d()
{
	mostrar();
	cout << "dni:" << dni << endl;
}
Estudiante::Estudiante(string _nombre, int _edad, string _carrera) :Persona(_nombre, _edad)
{
	carrera = _carrera;
}
void Estudiante::show()
{
	mostrar();
	cout << "mi carrera es:" << carrera << endl;
}
Universitario::Universitario(string _nombre, int _edad, string _carrera, int _grado) :Estudiante(_nombre, _edad, _carrera)
{
	ano = _grado;
}
void Universitario::ver()
{
	show();
	cout << "estoy en grado:" << ano << endl;
}
int main()
{
	Universitario p1("shelo", 25, "ingeniero", 1);
	p1.ver();






	system("pause");
	return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
