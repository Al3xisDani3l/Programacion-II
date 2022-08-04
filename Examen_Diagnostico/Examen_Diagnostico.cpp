// Examen_Diagnostico.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>


struct Promedio
{
	float Nota1;
	float Nota2;
	float Nota3;
};

struct Alumno
{
	char nombre[20];
	char Sexo[1];
	unsigned int Edad;
	Promedio promedio;

};

Alumno _alumnos[5];

void PedirDatos() {

	for (size_t i = 0; i < 5; i++)
	{
		printf_s("Introduce el nombre del alumno:\n");
		scanf_s("%s", _alumnos[i].nombre);
		printf_s("\nIntroduce el Sexo del alumno, M para maculino F para femenino:\n");
		scanf_s("%c", _alumnos[i].Sexo);
		printf_s("\nIntroduce la edad del alumno:\n");
		scanf_s("%i", &_alumnos[i].Edad);

		printf_s("\n\nIntroduce la nota numero 1:\n");
		scanf_s("%f", &_alumnos[i].promedio.Nota1);
		printf_s("\nIntroduce la nota numero 2:\n");
		scanf_s("%f", &_alumnos[i].promedio.Nota2);
		printf_s("\nIntroduce la nota numero 3:\n");
		scanf_s("%f", &_alumnos[i].promedio.Nota3);




	}
}

float promedio(Alumno alumno) {
	float promedio = (alumno.promedio.Nota1 + alumno.promedio.Nota2 + alumno.promedio.Nota3) / 3;
	return promedio;
}

void MostrarDatos(Alumno alumno) {

	printf("\nEl alumno con la calificacion!\n");
	printf("Nombre: %s\n", alumno.nombre);
	printf("sexo: %c\n", alumno.Sexo);
	printf("Edad: %i\n", alumno.Edad);
	printf("Promedio: %f \n", promedio(alumno));
}

void MayorPromedio() {


	Alumno mayor = _alumnos[0];

	for (size_t i = 1; i < 5; i++)
	{
		if (promedio(mayor) < promedio(_alumnos[i]))
		{
			mayor = _alumnos[i];
		}

	}

	MostrarDatos(mayor);
}




int main()
{
	PedirDatos();
	MayorPromedio();
	

}


class Data
{
public:
	Data();
	~Data();

private:

};

Data::Data()
{
}

Data::~Data()
{
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
