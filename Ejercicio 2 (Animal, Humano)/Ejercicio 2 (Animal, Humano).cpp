// Ejercicio 2 (Animal, Humano).cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include<iostream>
#include<stdlib.h>
using namespace std;



class Animal {


private: //atributos.

	string nombre;
	int  edad;

public: //metodos.

	Animal(string, int);//constructor.

	virtual void comer();
	virtual void dormir();
};



Animal::Animal(string _nombre, int _edad) {

	nombre = _nombre;
	edad = _edad;

}

void Animal::comer() {

	cout << nombre << " tiene " << edad << " anios " << "y esta comiendo " << endl;

}

void Animal::dormir() {

	cout << nombre << " esta durmiendo  " << endl;
}




class Humano : public Animal {

private: //atributos 

	string nacionalidad;
public: //metodos

	Humano(string, int, string);//constructor.
	void comer();
	void dormir();

};



Humano::Humano(string _nombre, int _edad, string _nacionalidad) : Animal(_nombre, _edad) {

	nacionalidad = _nacionalidad;

}

void Humano::comer() {

	Animal::comer();

	cout << "en la mesa." << endl;
}

void Humano::dormir() {

	Animal::dormir();
	cout << " en la cama." << endl;
}


class Perro :public Animal {

private:
	string raza;

public:
	Perro(string, int, string);
	void comer();
	void dormir();


};

Perro::Perro(string _nombre, int _edad, string _raza) :Animal(_nombre, _edad) {

	raza = _raza;
}

void Perro::comer() {

	Animal::comer();

	cout << "en su comedero." << endl;
}

void Perro::dormir() {

	Animal::dormir();

	cout << "en el suelo" << endl;
}




int main() {

	Animal* vector[3];


	vector[0] = new Perro("Bobby", 4, "Basset Hound");

	vector[0]->comer();

	vector[0]->dormir();

	vector[1] = new Humano("Alvaro", 37, "Español");

	vector[1]->comer();

	vector[1]->dormir();



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
