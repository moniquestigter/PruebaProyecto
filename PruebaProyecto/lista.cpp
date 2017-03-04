#include "lista.h"

Lista::Lista()
{
    longiLista = 0;
    inicio = NULL;
}

Archivo * Lista::agregar(Archivo *arch){
    if(longiLista == 0){
        inicio = arch;
        longiLista++;
        return arch;
    }
    else{
        Archivo * temp = inicio;
        for(int a = 0; a<longiLista; a++){
            if(temp == NULL){
                temp = arch;
                temp->ant = arch->ant;
                longiLista++;
                return arch;;
             }
             temp = temp->sig;
         }
     }
    return NULL;
}

void Lista::eliminar(Archivo * arch){
    Archivo * temp = this->inicio;
    for(int a = 0; a<longiLista; a++){
        if(temp->nombre == arch->nombre){
            while(temp->sig !=NULL){
                temp->sig->ant = temp->ant;
                temp->ant->sig = temp->sig;
            }
            longiLista--;
        }
        temp = temp->sig;
    }
}

/*Archivo* Lista::buscar(string ruta){
    Archivo * temp = inicio;
    for(int a = 0; a<longiLista; a++){
        if(temp->nombre.find(ruta))
            return temp;
        temp = temp->sig;
    }
}*/
