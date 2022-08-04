#pragma once
#include <iostream>

using namespace std;

class Persona {
private:
    int _piernas;
    int _brazos;
    int _cabeza;
    string _apellidos;
   
protected:
    string _nombre;
public:
    Persona(string n, string a);
    int piernas() { return _piernas; };
    int brazos();
    int cabeza() { return _cabeza; };
    static string color_ojos;
    static string color_pelo;
    float altura(float a) { return a; };
    float peso(float p);
    static int edad;
    string nombre() { return _nombre; };
    string apellidos() { return _apellidos; };

};

Persona::Persona(string n, string a)
{
    _piernas = 2;
    _brazos = 2;
    _cabeza = 1;
    _nombre = n;
    _apellidos = a;
}

int Persona::brazos()
{
    return _brazos;
}

string Persona::color_ojos = "negros";
string Persona::color_pelo = "negro";

float Persona::peso(float p)
{
    return p;
}

int Persona::edad = 0;
