#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Nodo* CrearNodo(Libro* libro){
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nodo){
            printf("Error al crear nodo, no hay memoria!\n");
            exit(1); // to exit the program immedietly.
    }else{
        strncpy(nodo->libro.titulo, libro->titulo, 50);
        strncpy(nodo->libro.autor, libro->autor, 50);
        strncpy(nodo->libro.isbn, libro->isbn, 13);
            
            nodo->siguiente = NULL;
        return nodo;
    }
    
    
}

void DestruirNodo(Nodo* nodo){
    free(nodo);
}

void InsertarPrincipio(Lista* lista, Libro* libro){
    Nodo* nodo = CrearNodo(libro);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void InsertarFinal(Lista* lista, Libro* libro){
    
    Nodo* nodo = CrearNodo(libro);
    if (lista->cabeza == NULL){
        lista->cabeza = nodo;
    }else{
        Nodo* puntero = lista->cabeza;
        //Mientras el siguiente elemento de la lista exista
        while (puntero->siguiente)
        {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}
void InsertarDespues(int n, Lista* lista, Libro* libro){
    Nodo* nodo = CrearNodo(libro);

    if (lista->cabeza == NULL){
        lista->cabeza = nodo;
    }else{
        int posicion = 0;
        Nodo* puntero = lista->cabeza;
        //Mientras el siguiente elemento de la lista exista
        while (puntero->siguiente && posicion<n)
        {
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}


Libro* Obtener(int n, Lista* lista ){
    if (lista->cabeza == NULL){
        return NULL;
    }else{
        Nodo* puntero = lista->cabeza;
        int posicion=0;
        while (posicion<n && puntero->siguiente){
            puntero = puntero->siguiente;
            posicion++;
        }
        if (posicion != n){
            return NULL;
        }else{
            return &puntero->libro;
        }
    }
}

int Contar(Lista* lista){
    return lista->longitud;
}

int EstaVacia(Lista* lista){
    return lista->cabeza == NULL;
}

void EliminarPrincipio(Lista* lista){
    if (lista->cabeza)
    {
        Nodo* eliminado = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        DestruirNodo(eliminado);
        lista->longitud--;
    }
}

void EliminarFinal(Lista* lista){
    if (lista->cabeza){
        if (lista->cabeza->siguiente)
        {
            Nodo* puntero = lista->cabeza;
            //Mientras el siguiente elemento de la lista exista
            while (puntero->siguiente->siguiente)
            {
                puntero = puntero->siguiente;
            }
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        }else{
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        }
        
    }
    
}

void EliminarElemento(int n, Lista* lista){
    if (lista->cabeza){
        if (n == 0){
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
        }else if (n < lista->longitud){
            int posicion = 0;
            Nodo* puntero = lista->cabeza;
            //Mientras el siguiente elemento de la lista exista
            while (posicion<(n-1))
            {
                puntero = puntero->siguiente;
                posicion++;
            }
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = puntero->siguiente->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
        }
        
        
    }
}

void Imprimir(Lista* lista){
    printf("Libro\t Autor \t ISBN\n");
    if (lista->cabeza){
        Nodo* puntero = lista->cabeza;
        if (lista->cabeza->siguiente)
        {
            //Mientras el siguiente elemento de la lista exista
            while (puntero->siguiente)
            {
                printf("%s\t%s\t%s\n",puntero->libro.titulo,puntero->libro.autor,puntero->libro.isbn);
                puntero = puntero->siguiente;
            }   
        }else
        {
            printf("%s\t%s\t%s\n",puntero->libro.titulo,puntero->libro.autor,puntero->libro.isbn);
        }
        
        
    }else
    {
        printf("-- \t Sin datos para mostrar \t --");
    }
    printf("-- \t -- \t -- \t -- \t --");
    
}