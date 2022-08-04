// Proyecto Final Equipo 5
// Alexis Daniel Hernandez Gamez  - 180263
// Genesis Erizel Arteaga Rangel - 182129
// Francisco Antonio Hernandez Mena - 180233


#include <iostream>
#include <string.h>
#include "kNN.h"
#include "Dataset.h"
#include "Point.h"


#define STRING_SIZE_MAX 128





using namespace std;

int main()
{
   
   
    float datos[4];

    

    string path;//= "D:\ProgramacionII\iris.data.csv";

    cout << "Hola bienvenido para empezar introduce la direccion del archivo a analizar:\n";
    cin >> path;

    Dataset* _dataset = new Dataset(path);

    cout << endl<<endl << "Dataset cargado!" << endl<<endl;

    cout << "Introduce las cordenadas para calcular el punto"<<endl<<endl;

    

    for (size_t i = 0; i < 4; i++)
    {
        cout << "cordenada x" << i + 1 << ": ";
        cin >> datos[i];
        cout << endl;
    }



    Point* _puntoDePrueba = new Point(datos, 4, 0);

    _puntoDePrueba->Print();
    
    cout << endl;


   
    

    kNN* _knn = new kNN(_dataset, 3, 3);


    cout << endl << "-----Calculo de distancias-----" << endl;


    int _claseMasCercana = _knn->getClass(_puntoDePrueba);


    _puntoDePrueba->SetClass(_claseMasCercana);
    

    _puntoDePrueba->Print();
   // std::cout <<endl <<"\nLa clase mas cercana es : "<<resultado<<endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
