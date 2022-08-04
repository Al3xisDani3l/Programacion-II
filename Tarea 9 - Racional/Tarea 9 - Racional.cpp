// Tarea 9 - Racional.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class Racional
{
public:
	Racional();
	Racional(int a, int b);
	Racional& Inverso();
	double Decimal();
	~Racional();
	int a;
	int b;

private:
	
};

Racional::Racional()
{
	int a = 0;
	int b = 1;
}

Racional::Racional(int a, int b)
{
	if (a == b)
	{
		this->a = 1;
		this->b = 1;
	}
	else
	{
		this->a = a;
		this->b = b;
	}
	
}

Racional& Racional::Inverso()
{
	return *(new Racional(this->b,this->a));
}

double Racional::Decimal()
{
	return (double)a / (double)b;
}

Racional::~Racional()
{
}




Racional& operator + (const Racional& p1, const Racional& p2) {

	return *(new Racional((p1.a * p2.b) + (p2.a * p1.b), p1.b * p2.b));


}

Racional& operator - (const Racional& p1, const Racional& p2) {

	return *(new Racional((p1.a * p2.b) - (p2.a * p1.b), p1.b * p2.b));


}

Racional& operator / (const Racional& p1, const Racional& p2) {

	return *(new Racional(p1.a * p2.b, p1.b * p2.a));

}

Racional& operator * (const Racional& p1, const Racional& p2) {

	return *(new Racional(p1.a * p2.a, p1.b * p2.b));

}

Racional& operator + (const Racional& p1, const int p2) {

	return *(new Racional(p1.a + (p2 * p1.b), p1.b));


}

Racional& operator - (const Racional& p1, const int p2) {

	return *(new Racional(p1.a - (p2 * p1.b), p1.b));


}

Racional& operator / (const Racional& p1, const int p2) {

	Racional aux = *(new Racional(p2, 1));
	return p1 / aux;

}

Racional& operator * (const Racional& p1, const int p2) {



	Racional aux = *(new Racional(p2, 1));

	return p1 * p2;


}


ostream& operator << (ostream& o, const Racional& p)
{
	if (p.a == p.b)
	{
		o << 1;
	}
	else if (p.a % p.b == 0)
	{
		o << p.a / p.b;
	}
	else
	{
		o << p.a << "/" << p.b;
	}

	return o;
}

istream& operator >> (istream& o, Racional& p) {

	int co;
	int divi;
	char diago;

	o >> co >> diago >> divi;

	p.a = co;
	p.b = divi;

	return o;

}





int main()
{
	
	Racional pl;

	cin >> pl;


	Racional p1 = *(new Racional(1, 2));
	
	Racional p2 = *(new Racional(2, 3));

	Racional p3 = p1 + p2;

	Racional p4 = p3.Inverso();

	Racional p5 = p3 * p4;

	Racional p6 = *(new Racional(36, 6));

	Racional p7 = p3 + 15;

cout << p1 << endl << p2 << endl << p3 << endl << p4 << endl << p5 << endl << p6 << endl << p7 << endl << p7.Decimal();

   
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
