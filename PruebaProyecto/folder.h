#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <QPushButton>
#include <QIcon>
#include <string.h>
#include <QLabel>
#include <QWidget>
#include "archivo.h"
#include "lista.h"

using namespace std;

class Folder: public Archivo
{
public:
    Folder(string nombre, string ruta, QWidget * wid);
    ~Folder();
    string nombre;
    string ruta;
    QWidget * widget;
    string getRuta();
    Lista * list;
    void add(Archivo * arch);
    void erase(Archivo * arch);

    QLabel nom;
};

#endif // FOLDER_H
