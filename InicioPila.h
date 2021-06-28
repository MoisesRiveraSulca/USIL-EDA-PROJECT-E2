#ifndef __INICIO_PILA_H__
#define __INICIO_PILA_H__

#include <iostream>
#include "type.h" 
using namespace std;

struct Nodo{
  char dato;
  string tipo;
  Nodo *siguiente;
};
//Prototipo de función
void push(Nodo *&,T1);
void pop(Nodo *&, T1 &);
char nextP(Nodo *&);
bool vacio(Nodo *&);

//Función de agregar un nodo a la pila
void push(Nodo *&pila, char n, string t){
  Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo -> dato = n;
  nuevo_nodo -> siguiente = pila;
  nuevo_nodo -> tipo = t;
  pila = nuevo_nodo;
}

void pop(Nodo *&pila){
  Nodo *aux = pila;
  pila = aux->siguiente;
  delete aux;
}

bool vacio(Nodo *&pila){
  bool empty=true;
  if(pila != NULL){
    empty=false;
  }
    return empty;
}

char nextP(Nodo *&pila){
  char n;
  if (vacio(pila)==0){
    Nodo *aux = pila;
    n = aux->dato;
    
    //pila = aux->siguiente;
  }else{
    n = '%';
  }
  return n;
}


#endif
