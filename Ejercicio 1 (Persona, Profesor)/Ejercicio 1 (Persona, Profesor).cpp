// Ejercicio 1 (Persona, Profesor).cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

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

Persona::Persona(string _nombre, int _edad)
{
	nombre = _nombre;
	edad = _edad;
}

void Persona::mostrar()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Edad: " << edad << endl;
}

class Alumno : public Persona
{
public:
	Alumno(string _nombre, int _edad, float _calificacion) :Persona(_nombre, _edad) {
		
		notaFinal = _calificacion;
	}
	void mostrar() {
		Persona::mostrar();
		cout << "Nota Final: " << notaFinal << endl;
	}

private:
	string codigoAlumno;
	float notaFinal;
};

class Profesor:public Persona
{
public:
	Profesor(string _nombre, int _edad, string _materia) :Persona(_nombre, _edad) {

		materia = _materia;
	}
	
	void mostrar() {
		Persona::mostrar();
		cout << "Materia: " << materia << endl;
	}

private:
	string materia;
};






int main()
{
	Persona* vector[3];

	vector[0] = new Alumno("Alejandro", 20, 18.9);
	vector[1] = new Alumno("Maria", 19, 15.5);
	vector[2] = new Profesor("Jose", 25, "Algoritmos");

	vector[0]->mostrar();
	cout << endl;
	vector[1]->mostrar();
	cout << endl;
	vector[2]->mostrar();
	cout << endl;

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
