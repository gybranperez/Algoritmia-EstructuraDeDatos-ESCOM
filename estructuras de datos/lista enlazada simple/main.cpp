#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#include"lista.h"

int main() {
    int op = 0;
    Lista lista;


    do{
        Libro libro;
        char titulo[50], autor[50], ISBN[13];
        cout << "Ingrese el titulo del libro: ";
        cin >> titulo;
        cout << "Ingrese el autor del libro: ";
        cin >> autor;
        cout << "Ingrese el ISBN del libro: ";
        cin >> ISBN;
        strcpy(libro.titulo,titulo);
        strcpy(libro.autor,autor);
        strcpy(libro.isbn,ISBN);
        InsertarPrincipio(&lista, &libro);
        Imprimir(&lista);
        cout << "\nQuiere ingresar otro libro (1 = si, 2 = no): ";
        cin >> op;
        cout << "-----------------------"<< endl;
    }while(op == 1);

    return 0;
}
