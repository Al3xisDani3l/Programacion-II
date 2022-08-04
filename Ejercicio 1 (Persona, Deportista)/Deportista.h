#pragma once
#include <iostream>
#include "persona.h"
using namespace std;


class Deportista : public Persona
{
protected:
    string _deporte;
public:
    Deportista(string n, string a, string deporte) : Persona(n, a) { this->_deporte = deporte; };
    string deporte() { return this->_deporte; };
    string cambiar_nombre(Deportista& d, string n)
    {
        if (&d == this) return this->_nombre = n;
        else return "El objeto seleccionado no soy yo";
    }
};