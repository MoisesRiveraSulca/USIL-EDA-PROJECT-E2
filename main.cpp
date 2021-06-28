#include <iostream>
using namespace std;
#include "PostOrder.h"
#include "PreOrder.h"
#include "InicioPila.h"
#include "CrearArbol.h"
#include "Cola.h"

PostOrder Po;
PreOrder Pr;
Nodo *Post = NULL;
Nodo *Pre = NULL;
NodoC *Inicio;
NodoC *Fin;
NodoC *Aux;
NodoA *M = NULL;
NodoA *Padre =NULL;

int main(){
  
  string operacion;
  cout<<"Ingrese su operación: "; 
  getline(cin,operacion);
  
  agregarTotal(Inicio, Fin, operacion);
  Aux = Inicio;
  Pr.convertirToPre(Pre, operacion);
  Po.convertirToPost(Post, operacion);


  

  

  








  return 0;
}
