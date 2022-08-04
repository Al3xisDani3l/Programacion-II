// T5 - Composicion de clases.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

class Detalle {
	string descripcionProducto;
	int cantidad;
	double precio;
public:
	Detalle():Detalle(0,"",0){}
	Detalle(int cantidad, string descripcionProducto, double precio) {
		this->cantidad = cantidad;
		this->descripcionProducto = descripcionProducto;
		this->precio = precio;
	}
	~Detalle();
	friend class Factura;

	string GetDescripcion() {
		return descripcionProducto;
	}

	void SetDescripcion(string val) {
		descripcionProducto = val;
	}

	int GetCantidad() {
		return cantidad;
	}

	void SetCantidad(int c) {
		cantidad = c;

	}

	double GetPrecio() {
		return precio;
	}

	void SetPrecio(double p) {
		precio = p;
	}





};

ostream& operator <<(ostream& os, Detalle* d) {

	os <<  d->GetDescripcion() << "\n" << d->GetCantidad() << " X " << d->GetPrecio() << "\t\t\t" << d->GetCantidad() * d->GetPrecio() << "$";
	return os;
}


istream& operator >>(istream& in, Detalle* d) {

	string descripcionProducto;
	int cantidad;
	double precio;

	cout << endl;
	cout << "Descripcion del producto: ";
	in >> descripcionProducto;
	d->SetDescripcion(descripcionProducto);
	cout << endl;
	cout << "Cantidad: ";
	in >> cantidad;
	d->SetCantidad(cantidad);
	cout << endl;
	cout << "Precio del producto: ";
	in >> precio;
	d->SetPrecio(precio);

	
	

	return in;



}

class Factura {
	string razonSocial;
	string RUC;
	string numeroFactura;
	double subTotal;
	static double IVA;
	double total;
	vector<Detalle*> items;
public:

	Factura():Factura("","",""){}

	Factura(string razonSocial, string RUC, string numeroFactura) {
		this->razonSocial = razonSocial;
		this->RUC = RUC;
		this->numeroFactura = numeroFactura;
		this->subTotal = 0;
		this->total = 0;
	}
	~Factura() {
		items.~vector();
	}

	void addItem(Detalle* d) {
		subTotal += d->cantidad * d->precio;
		total = subTotal * IVA;
		items.push_back(d);


	}
	
	double SubTotal() {
		double sum = 0;

		for_each(items.begin(), items.end(), [&sum](Detalle* d) {sum += (d->GetCantidad() * d->GetPrecio()); });
		subTotal = sum;
		return sum;
	}

	double Total() {

		double _total = 0;

		_total = SubTotal() + (IVA * SubTotal());
			
		return _total;
	}

	string GetRazonSocial() {
		return razonSocial;
	}

	void SetRazonSocial(string r) {
		razonSocial = r;

	}

	string GetRUC() {
		return RUC;
	}

	double GetIVA() {
		return IVA;
	}

	void SetIVA(double iva) {
		IVA = iva;
	}

	void SetRUC(string r) {
		RUC = r;

	}

	string GetNoFactura() {
		return numeroFactura;
	}

	void SetNoFactura(string r) {
		numeroFactura = r;

	}

	ostream& PrintItems(ostream& os) {

		for_each(items.begin(), items.end(), [&os](Detalle* d) {

			os << endl << d << endl;

			});

		return os;
	}



};


ostream& operator <<(ostream& os, Factura* f) {

	os << endl << "Numero de Factura: " << f->GetNoFactura();
	os << endl << "Razon social: " << f->GetRazonSocial();
	os << endl << "RUC: " << f->GetRUC();
	os << endl << "Detalles:" << endl;
	f->PrintItems(os);
	os << "\n\t\t\tSubTotal: " << f->SubTotal();
	os << "\n\t\t\tIVA     : " << f->GetIVA() * 100 << "%";
	os << "\n\t\t\t----------------";
	os << "\n\t\t\tTotal   : " << f->Total();

	return os;


}

class Distribuidora {
	vector<Factura*> facturas;
public:
	Distribuidora() {

	}
	~Distribuidora() {

	}

	void guardaFactura(Factura* f)
	{
		facturas.push_back(f);

	}

	void guardaFactura(vector<Factura*> f);  //NO IMPLEMENTAR

	void listaFacturas() {

		int cont = 1;
		cout << endl << "Lista de facturas" << endl;
		for_each(facturas.begin(), facturas.end(), [&cont](Factura* f) {

			cout << endl << "Factura numero : " << cont;
			cont++;
			cout <<endl << f<<endl;
			

			});

	}




	void imprimeFactura(string numFactura) {

		for_each(facturas.begin(), facturas.end(), [numFactura](Factura* f) {

			if (f->GetNoFactura() == numFactura)
			{
				cout << f;
				return;
			}

			});

		cout << endl << "Factura enexistente" << endl;

	}
	Factura* buscaFactura(string numFactura) {

		Factura* out = NULL;

		for_each(facturas.begin(), facturas.end(), [numFactura, &out](Factura* f) {

			if (f->GetNoFactura() == numFactura)
			{
				out = f;
			}

			});

		if (out == NULL)
		{
			cout << endl << "Factura enexistente" << endl;
		}
		
		
		return out;
	}
};



double Factura::IVA = 0.16;



int main()
{
	srand(time(NULL));

	
	int opc = 0, cont = 125;

	string _in;

	Distribuidora* _dist = new Distribuidora();

	Factura* _fact = new Factura();

	Detalle* _det = new Detalle();

	Factura* result;

	const string RAZONES_SOCIALES[] = { "Metalurgia", "Tecnologico","Servicios" };

	char sal;


	do
	{
		system("cls");

		cout << endl << "Agregar Factura : 1" << endl;
		cout << endl << "Listar facturas : 2" << endl;
		cout << endl << "Imprimir factura : 3" << endl;
		cout << endl << "salir : 0" << endl<<endl<<"Opcion :";
		cin >> opc;

		cout << endl << endl;



		switch (opc)
		{
		case 1:
			cout << "----Agregar Factura----" << endl << endl;

			_fact = new Factura(RAZONES_SOCIALES[rand() % 2], "10079631" + to_string(rand() % 999), "FN" + to_string(cont));
			cont++;

			do
			{
				cout << endl << "Agregar producto" << endl << endl;

				_det = new Detalle();
			
				cin >> _det;

				_fact->addItem(_det);

				cout << endl << "Desea continuar agregando productos S/N: ";
				cin >> sal;
				cout << endl;

			} while (sal == 's' || sal =='S');

			_dist->guardaFactura(_fact);

			break;
		case 2:

			_dist->listaFacturas();

			break;
		case 3:
			cout << "Buscar Factura" << endl << endl;

			cout << "Numero de factura: ";
			cin >> _in;

			result  =  _dist->buscaFactura(_in);

			 if (result != NULL)
			 {
				 cout << endl << "Factura encontrada!" << endl << result << endl;
			 }


			break;
		

		default:
			break;
		}


		getchar();
		getchar();


	} while (opc != 0);


	

	
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
