#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
};

//Prototipos
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *, int);
Nodo *arbol = NULL;

int main(){
    menu();
    getch();
    return 0;
}

void menu (){
    int dato,opcion,contador=0;
    do{
        cout<<"\t.:MENU: ."<<endl;
        cout<<"l. Insertar un nuevo nodo"<<endl;
        cout<<"2. Mostrar el arbol completo"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion:";
        cin>>opcion;
        switch(opcion!=3){
            case 1: cout<<"\nDigite un numero:";
                cin>>dato;
                insertarNodo(arbol,dato); //Insertamos un nuevo nodo
                cout<<"\n";
                system("pause");
                break;
            case 2: cout<<"\nMostrando el arbol:";
                cin>>dato;
                mostrarArbol(arbol,contador); //Insertamos un nuevo nodo
                cout<<"\n";
                system("pause");
                break;
        }
        system("cls");
    }while(opcion != 2);
}




Nodo *crearNodo(int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;
}

//Función para insertar eLementos en eL arboL
void insertarNodo(Nodo *&arbol,int n){
    if(arbol == NULL){ //Si e¿ arboL esta vacio
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else{ //Si eL arboL tiene un nodo o mas
        int valorRaiz = arbol->dato; //Obtenemos eL vaLor de La raíz
        if(n < valorRaiz){ //Si eL eLemento es menor a La raiz, insertamos en izq
            insertarNodo(arbol->izq,n);
        }
        else{//Si el eLemento es mayor a La raíz, insertamos en der
            insertarNodo(arbol->der,n);
        }
    }
}

void mostrarArbol(Nodo *arbol, int cont)
{

    if(arbol == NULL){ //Si eL arboL esta vacio
        return;
    }
    else{
        mostrarArbol(arbol->der,cont+1);
        for(int i=0;i<cont;i++){
            cout<<"     ";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq,cont+1);
    }
}