// Tarea 6 - Cuenta.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;
class Cuenta
{
public:
	Cuenta(size_t saldo_i);
	~Cuenta();
	void Abono(size_t n);
	void Cargo(size_t n);
	size_t Saldo();


private:
	int saldo;

};

Cuenta::Cuenta(size_t saldo_i)
{
	if (saldo_i < 0)
	{
		saldo = 0;
		std::cout << std::endl << "El saldo " << saldo_i << " es invalido se inicializara en cero!" << std::endl;
	}
	else
	{
		saldo = saldo_i;
	}
}

Cuenta::~Cuenta()
{
}

void Cuenta::Abono(size_t n)
{
	if (!(saldo - n < 0))
	{
		saldo -= n;
	}
	else
	{
		std::cout << std::endl << "El monto a abonar excede el saldo de la cuenta." << std::endl;
	}
}

void Cuenta::Cargo(size_t n)
{
	saldo += n;
}

size_t Cuenta::Saldo() 
{

	return saldo;
}




int main()
{
	//a) Saldo inicial de 1000 pesos
	Cuenta* cuenta = new Cuenta(1000);

	//b) Abone 600
	cuenta->Abono(600);

	//c) Imprimir saldo

	cout << "El saldo de la cuenta es : " << cuenta->Saldo()<<endl;

	//d) cargue 200
	cuenta->Cargo(200);

	//e) imprima el saldo

	cout << endl << "El saldo de la cuenta es : " << cuenta->Saldo() << endl;

	cuenta->Abono(700);
   
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
