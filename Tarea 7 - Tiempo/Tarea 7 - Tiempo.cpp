 // Tarea 7 - Tiempo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class Tiempo
{
public:
	Tiempo(size_t segundos) {

		_segundos = segundos % 60;

		_minutos = ((segundos - _segundos) / 60)% 60;

		_horas = (((segundos - _segundos) / 60) /60)%24;

		_dias = (((segundos - _segundos) / 60) / 60) / 24;

	}

	Tiempo(size_t horas, size_t minutos, size_t segundos):Tiempo((horas*3600)+(minutos*60)+segundos) {
		
	}

	void MostrarTiempo() {

		if (_dias > 0)
		{
			cout << _dias << " dias: ";
		}

		if (_horas < 10)
		{
			cout << "0" << _horas << ":";
		}
		else
		{
			cout << _horas << ":";
		}

		if (_minutos < 10)
		{
			cout << "0" << _minutos << ":";
		}
		else
		{
			cout << _minutos << ":";
		}

		if (_segundos < 10)
		{
			cout << "0" << _segundos;
		}
		else
		{
			cout << _segundos;
		}

	

		

	}

	
	

private:
	size_t _horas;
	size_t _minutos;
	size_t _segundos;
	size_t _dias;
};



int main()
{

	Tiempo* time1 = new Tiempo(38123); //10:35:23 
	Tiempo* time2 = new Tiempo(5, 37, 67);

	cout << "El tiempo es : ";
	time1->MostrarTiempo();
	cout << endl;

	cout << "El tiempo es : ";
	time2->MostrarTiempo();
	cout << endl;
    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
