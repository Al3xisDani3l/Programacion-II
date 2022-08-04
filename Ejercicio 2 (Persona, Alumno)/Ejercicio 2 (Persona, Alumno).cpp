// Ejercicio 2 (Persona, Alumno).cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class Persona
{
public:
	Persona(string, int);
	void mostrarPersona();

private:
	string nombre;
	int edad;
};

Persona::Persona(string _nombre, int _edad)
{
	nombre = _nombre;
	edad = _edad;
}

void Persona::mostrarPersona()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Edad: " << edad << endl;
}


class Alumno: public Persona
{
public:
	Alumno(string _nombre, int _edad,string _codigoAlumno, float _calificacion):Persona( _nombre,_edad){
		codigoAlumno = _codigoAlumno;
		notaFinal = _calificacion;
	}
	void mostrarAlumno() {
		mostrarPersona();
		cout << "Codigo Alumno: " << codigoAlumno << endl;
		cout << "Nota Final: " << notaFinal << endl;
	}

private:
	string codigoAlumno;
	float notaFinal;
};




int main()
{
	Alumno alumno1("Alejandro", 20, "12312312", 9.5);

	alumno1.mostrarAlumno();  
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


