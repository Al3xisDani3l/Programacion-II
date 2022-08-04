// Ejercicio 1 (Persona, Deportista).cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "deportista.h"

using namespace std;




int main()
{
    Deportista deportista("Raul", "Gallardo Cuadrado", "Atletismo");
    cout << "Un Deportista:" << endl;
    cout << "Nombre: " << deportista.nombre() << endl;
    cout << "Apellidos: " << deportista.apellidos() << endl;
    cout << "Deporte: " << deportista.deporte() << endl;
    deportista.color_ojos = "verdes";
    cout << "Color de los ojos: " << deportista.color_ojos << endl;
    //Deportista cualquiera("h", "h", "h");
    cout << deportista.cambiar_nombre(deportista, "Mario") << endl;
    cout << "Nuevo Nombre: " << deportista.nombre() << endl;


    /* El puntero * nos permite apuntar a un objeto, reservando un espacio en la memoria
    para el tipo de objeto seleccionado */

    Deportista* d;
    d = &deportista;
    cout << d->nombre() << endl;


    system("PAUSE");
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
