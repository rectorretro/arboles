#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
}*aux,*arbol=NULL;
Nodo *crearNodo(int);
//Nodo *arbol=NULL;

void mostrarArbolV(Nodo *,int);
void insertarNodo(Nodo *&,int,int);

int main(){
    srand(time(NULL));
    int cara,aguila=0,sol=0,cont=0;
    int numero;
    cout << "Veces a lanzar la moneda: ";
    cin >> numero;
    cout << endl;
    insertarNodo(arbol,0,0);
    for(int j=0; j<=99; j++){
        for(int i=0; i<=numero-1; i++){
            cara = 1 + rand()%2;
         cout << cara << " ";
         if(cara==1){
            aguila++;
     //
         }else if(cara==2){
             sol++;
       //
         }
         //insertarNodo(arbol, )
    }
    cout << endl;
   }
   insertarNodo(arbol,aguila,2);
   insertarNodo(arbol,sol,2);
   cout <<"Aguila:" << aguila<< endl;
   cout <<"Sol:" << sol<< endl;;
   cout << endl;
   mostrarArbolV(arbol,cont);


    return 0;
}


void mostrarArbolV(Nodo *arbol, int cont){
    if(arbol==NULL){
        return;
    }
    else{
        mostrarArbolV(arbol->der, cont+1);
        for(int i=1; i<cont; i++)
        {
            cout << "-";
        }
        cout << arbol->dato << endl;
        mostrarArbolV(arbol->izq, cont+1);
    }
}

Nodo *crearNodo(int n){
    Nodo *nuevo_nodo= new Nodo();

    nuevo_nodo->dato=n;
    nuevo_nodo->der=NULL;
    nuevo_nodo->izq=NULL;

    return nuevo_nodo;

}

//funcion para insertar elementos a un arbol
void insertarNodo(Nodo *&arbol, int n, int cara){
    if(arbol==NULL){//si el arbol esta vacio
        Nodo *nuevo_nodo=crearNodo(n);
        arbol=nuevo_nodo;
        return;

    }
    else{//si el arbol tiene nodos
        int valorRaiz= arbol->dato;
        if(n!=valorRaiz){
            if(n<valorRaiz && cara == 1){//si n es menor a la izquierda
                insertarNodo(arbol->izq,n,cara);
            }
            else{//si n es mayor insertar a la derecho
                insertarNodo(arbol->der,n,cara);
            }
        }
    }

}
