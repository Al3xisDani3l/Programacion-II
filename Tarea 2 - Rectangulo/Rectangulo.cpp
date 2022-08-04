#include "Rectangulo.h"



void Rectangulo::SetAltura(float n){
	if (n > 0)
	{
		alto = n;
	}
	else
	{
		alto = 1;
	}
	


}

void Rectangulo::SetAncho(float n) {
	if (n>0)
	{
		ancho = n;
	}
	else
	{
		ancho = 1;
	}
	
}

float Rectangulo::GetArea() {
	return alto * ancho;
}

float Rectangulo::GetPerimetro() {
	return (2 * alto) + (2 * ancho);
}
