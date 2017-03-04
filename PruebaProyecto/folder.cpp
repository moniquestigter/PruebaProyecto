#include "folder.h"

Folder::Folder(string n, string r,QWidget *wid)
{
    nombre = n;
    ruta = r;
    widget = wid;
    list = new Lista();

}

Folder::~Folder(){

}

string Folder::getRuta(){
    return ruta;
}

void Folder::add(Archivo *arch){
    list->agregar(arch);
}

void Folder::erase(Archivo *arch){
    list->eliminar(arch);
}
