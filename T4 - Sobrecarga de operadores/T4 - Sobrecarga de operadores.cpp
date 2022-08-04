// T4 - Sobrecarga de operadores.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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
	return *(new Racional(this->b, this->a));
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

	


	Racional p1;

	cout << "Introduce el primer racional con el formato <Numero><letra><Numero>" << endl;
	cin >> p1;
	cout << endl;

	Racional p2;
	cout << "Introduce el segundo racional con el formato <Numero><letra><Numero>" << endl;
	cin >> p2;
	cout << endl;

	Racional p3 = p1 + p2;

	cout << endl << "La suma de " << p1 << " + " << p2 << " = " << p3 << endl;
	cout << endl;
	cout << "La inversa de " << p3 << " es: " << p3.Inverso() << endl;
	cout << endl;
	cout << "Multiplicacion de " << p3 << " * " << p3.Inverso() << " = " << p3 * p3.Inverso() << endl;
	cout << endl;
	Racional p4;
	cout << "Introduce un nuevo racional para dividir " << p1 << ": ";
	cin >> p4;
	cout << endl;
	Racional p5 = p1 / p4;

	cout << endl << "(" << p1 << ")/(" << p4 << ") = " << p5<<endl;
	cout << endl;
	cout << "La representacion decimal de " << p5 << " es: " << p5.Decimal();
	cout << endl;
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
