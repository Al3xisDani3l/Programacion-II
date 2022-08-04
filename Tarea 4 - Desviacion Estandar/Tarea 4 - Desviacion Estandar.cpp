// Tarea 4 - Desviacion Estandar.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "DesviacionEstandar.h"
using namespace std;

int main()
{
    float datos[] = { 1,2,7,8,9,15,24,17,78,3 };

    DesviacionEstandar* ds = new DesviacionEstandar(datos,10);

   

    ds->Print(cout);

    float rDesviacion = ds->Calculate();

    cout << "la desviacion estandar es: " << rDesviacion << endl;


   

    delete ds;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
