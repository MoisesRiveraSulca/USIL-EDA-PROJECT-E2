#ifndef __CREAR_ARBOL_H__
#define __CREAR_ARBOL_H__
#include <iostream>
#include "InicioPila.h"

struct NodoA{
  string dato;
  string tipo;
  NodoA *izq;
  NodoA *der;
  NodoA *padre;
};
//Prototipos
NodoA *crearNodo(string, string, NodoA);
void insertarNodoArbol(NodoA *&,string,string, NodoA);
void postOrden(NodoA *);
void mostrarArbol(Nodo *&,int);

//Función apra crear un nuevo Nodo
NodoA *crearNodo(string n, string t,NodoA *padre){
  NodoA *nuevo_nodo = new NodoA();
  nuevo_nodo->dato = n;
  nuevo_nodo->tipo = t;
  nuevo_nodo->der = NULL;
  nuevo_nodo->izq = NULL;
  nuevo_nodo->padre = padre;
  return nuevo_nodo;
}

//Función para insertar elementos en el arbol 
void insertarNodoArbol(NodoA *&arbol, string n, string t,NodoA *padre){
  if(arbol==NULL){
     NodoA *nuevo_nodo = crearNodo(n,t,arbol);
     arbol = nuevo_nodo; 
     //cout<<"Insertado con exitoxd\n";
    
  }else{
    if(t == "Operando" && arbol->tipo =="Operando"){
      arbol = padre;
      insertarNodoArbol(padre->izq,n,t,arbol);
    }else{
      insertarNodoArbol(arbol->der,n,t,arbol);
    }
  } 
}
void postOrden(NodoA *arb){
  if(arb ==NULL){
    return;
  }else{
    //postOrden(arb->izq);
    //postOrden(arb->der);
    //cout<<arb->dato<<" ";
  }
}

void mostrarArbol(NodoA *arbol, int cont){
  if(arbol==NULL){
    return;
  }else{
    mostrarArbol(arbol->der, cont+1);
    for(int i=0;i<cont;i++){
      cout<<"     ";
    }
    cout<<arbol->dato<<endl;
  }
}

#endif
