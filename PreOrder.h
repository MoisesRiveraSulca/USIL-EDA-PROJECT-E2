#ifndef __PRE_ORDER_H__
#define __PRE_ORDER_H__
#include "InicioPila.h"

class PreOrder{
  private:
  string operacion;
  Nodo *Pre;
  public:
  PreOrder();
  void convertirToPre(Nodo *&, string);  
  int jerarquiaPre(char);
};
PreOrder:: PreOrder(){}

void PreOrder :: convertirToPre(Nodo *&Salida, string str)
{
  Pre = Salida; 
  Nodo *Aux = NULL;
  for(int i=str.size()-1; i>=0; i--){
    char caracter = str[i];
    switch(caracter)
    {
      case '(':
        while(jerarquiaPre(nextP(Aux))!= 1){
          push(Salida, nextP(Aux),"");
          pop(Aux);
        }
        pop(Aux);
        
        break;
      case '^':
      case '*':
      case '/':
      case '+':
      case '-':
        while(jerarquiaPre(caracter)<= jerarquiaPre(nextP(Aux))){
            char n = nextP(Aux);
            pop(Aux);
            push(Salida, n, "Operador");
        }
        push(Aux, caracter, "");
  
        break;
      case ')':
        push(Aux, caracter,""); 
        break;
      default: push(Salida, caracter, "Operando");
    }
    
    
  }
  while(Aux!=NULL){
      push(Salida, nextP(Aux),"Operador");
      pop(Aux);
  }
  
}

int PreOrder :: jerarquiaPre(char n){
  int j = 0;
  //Convertir el char a string
  string ob;
  ob+=n;
  //Comparación
  if(ob == "^"){
    j = 4;
  }else if(ob == "*" || ob == "/"){
    j = 3;
  }else if(ob =="+" || ob =="-"){
    j = 2;
  }else if(ob == ")"){
    j = 1;
  }else if(ob =="%"){
    j = 0;
  }
  return j;


}
#endif
