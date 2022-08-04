// Tarea 3 - Formula General.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "FormulaGeneral.h"

using namespace std;
int main()
{
    FormulaGeneral fg;

    fg.SetA(1);
    fg.SetB(6);
    fg.SetC(3);

    float raiz1 = fg.CalculateX1();
    float raiz2 = fg.CalculateX2();

    std::cout << "Resultados de la raiz 1: "<< raiz1 <<endl;

    std::cout << "Resultados de la raiz 2: " << raiz2 << endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
