#pragma once

class Rectangulo
{
public:
	
	/*void SetAltura(float n);
	void SetAncho(float n);*/
	Rectangulo(float altura, float anchura);
	float GetArea();
	float GetPerimetro();

private:
	float alto, ancho;
};

Rectangulo::Rectangulo(float altura, float anchura) {
	alto = altura;
	ancho = anchura;
}




