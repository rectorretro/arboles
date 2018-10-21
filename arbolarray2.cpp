#include <iostream>
#include <conio.h>
using namespace std;
struct nodo{
    string dato;
    nodo *izq;
    nodo* dere;
}*aux,*arbol=NULL;

void insertarnodo(nodo *&, string);
nodo *nodocreacion(string);
void opciones(int);
void mostar(nodo *,int);

int main(){
    int caso;
    do{
        caso=0;
        cout << "1.-Insertar nodo" << endl;
        cout << "2.-Arreglo -> arbol" << endl;
        cout << "3.-Mostrar arbol"<< endl;
        cout << "4.-salir" << endl;
        cout << "opcion: ";
        cin >> caso;
        opciones(caso);
        system("cls");
    }while(caso!=4);

    getch();
    return 0;
}

void opciones(int caso){
    string num;
    int cor=0;
    string arreglo[11]={"hola","red","red1","are","esa","doll","hunt","seniro","coela","relex","rabia"};
    switch(caso){
case 1:
    do{
    cout << "Meta un dato(salir introdusca s): ";
    getline(cin,num);
    if(num == "salir"){
        return;
    }
    insertarnodo(arbol,num);
    system("cls");
    }while(num != "salir");

    break;
case 2:

    for (int i=0; i<11; i++){
    insertarnodo(arbol,arreglo[i]);
    }
    break;
case 3:
    mostar(arbol,cor);
    system("pause");
    break;
default:
    break;

    }
}

nodo *nodocreacion(string valor){

        nodo *aux = new nodo();
        aux->dato = valor;
        aux->dere = NULL;
        aux->izq = NULL;
    return aux;
}
void insertarnodo(nodo *&arbol, string valor){
    if (arbol == NULL){
            nodo *nuevo_nodo = nodocreacion(valor);
            arbol = nuevo_nodo;
    }else{
        string datoRaiz = arbol->dato;
        if(datoRaiz != valor){


            if(datoRaiz>valor){
            insertarnodo(arbol->izq, valor);
        }else{
            insertarnodo(arbol->dere, valor);
        }

            }


    }

}

void mostar(nodo *arbol,int conter){
    if(arbol == NULL){
        return;
    }else{
        mostar(arbol->dere, conter+1);
        for (int i=0; i<conter; i++){
            cout << "---->";
        }
        cout << arbol->dato << endl;
        //
        mostar(arbol->izq, conter+1);
    }


}
