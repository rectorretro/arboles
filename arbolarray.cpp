#include <iostream>
#include <conio.h>
using namespace std;
struct nodo{
    int dato;
    nodo *izq;
    nodo* dere;
}*aux,*arbol=NULL;

void insertarnodo(nodo *&, int);
nodo *nodocreacion(int);
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
    int num=0;
    int cor=0;
    int arreglo[11]={14,15,4,9,7,18,3,5,16,20,17};
    switch(caso){
case 1:
    do{
    cout << "Meta un dato(salir introdusca -1): ";
    cin >> num;
    if(num == -1){
        return;
    }
    insertarnodo(arbol,num);
    system("cls");
    }while(num != -1);

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

nodo *nodocreacion(int valor){

        nodo *aux = new nodo();
        aux->dato = valor;
        aux->dere = NULL;
        aux->izq = NULL;
    return aux;
}
void insertarnodo(nodo *&arbol, int valor){
    if (arbol == NULL){
            nodo *nuevo_nodo = nodocreacion(valor);
            arbol = nuevo_nodo;
    }else{
        int datoRaiz = arbol->dato;
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
