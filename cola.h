#ifndef __COLA_H__
#define __COLA_H__

#include<iostream>
#include "type.h"

using namespace std;

  struct NodoC{
    int dato;
    T1 valor;
    NodoC *siguiente;
  };

  //Prototipos de funciones 
  NodoC crearNodo();
  void insertarCola(NodoC *&,NodoC *&, int, T1);
  bool colaVacia(NodoC *);
  void agregarTotal(NodoC *&,Nodo *&,T1);
  int cantidadNodos(NodoC *&,Nodo *&);
  //Función para insertar elementos a una cola
  
  void insertarCola(NodoC *&frente, NodoC *&fin, int n,T1 s){
    NodoC *nuevo_nodo = new NodoC();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->valor = s;

    if(colaVacia(frente)){
      frente = nuevo_nodo;
    }else{
      fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
  }

  //Función para contar la cantidad de nodos de la cola
  int cantidadNodos(NodoC *&I, NodoC *&F){
    NodoC *nuevo = new NodoC();
    nuevo = I;
    int contador =1;
    while(nuevo != F){
      nuevo = nuevo->siguiente;
      contador++;
    }
    return contador;
  }

  //Función para determinar si la cola está vacía
  bool colaVacia(NodoC *frente){
    return (frente == NULL)?true : false;
  }

  //Agregar elementos de la operación
  void agregarTotal(NodoC *&frente, NodoC *&fin, T1 operacion){
    string concat ="";
    int contador = 1;
    for(int i=0;i<=operacion.size();i++){
      char op = operacion[i];
      switch(op)
      {
      case '(':
      case ')':
        if(concat!=""){
            insertarCola(frente,fin,contador,concat);
            concat="";
            contador++;
        }        
        concat+=op;
        insertarCola(frente,fin,0,concat);
        concat="";
        break;
      case '^':
      case '*':
      case '/':
      case '+':
      case '-':
        if(concat!=""){
            insertarCola(frente,fin,contador,concat);
            concat="";
            contador++;
        }
        concat+=op;
        insertarCola(frente,fin,contador,concat);
        contador++;
        concat="";
        break;
      default:
      concat+=op;
      /*if(concat+=op  "sen"||concat+=op == "cos"||concat+=op =="tan"||concat+=op =="ctg"||concat+=op =="sec"||concat+=op =="csc"||){
        insertarCola(frente,fin,contador,concat+=op);
        concat="";
        contador++;
      };*/
    }
    if(concat!=""){
            insertarCola(frente,fin,contador,concat);
            concat="";
            contador++;
        }
     
  }
}
#endif
