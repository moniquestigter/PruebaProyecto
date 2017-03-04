#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>

using namespace std;
class Archivo
{
public:
    Archivo();
    string tipo;
    string nombre;

    Archivo * sig;
    Archivo * ant;
};

#endif // ARCHIVO_H
