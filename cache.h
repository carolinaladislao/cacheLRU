//
// Created by Carol on 8/6/2024.
//

#ifndef CACHELRU_CACHE_H
#define CACHELRU_CACHE_H

#define TAM 150

typedef struct nodo{
    int num;
    struct nodo * sig;
    struct nodo * ant;
}Nodo;

typedef struct lista{
    Nodo * cabecera;
}Lista;


typedef struct cache{
    int tamanio;
    int ocupacion;
    Lista * cache;
    Nodo * hash[TAM];
}Cache;

Nodo * newNodo(int num);

Lista * newLista ();

Cache * newCache(int tam);

void insertarNodoListaApilando(Lista * lista, Nodo * nodo);

void solicitarNumero (Cache * cache, Lista * lista, int numero);

void desasociarElemento (Nodo * nodo);

void hacerEspacioEnCache(Cache * cache);

int buscarNumeroEnLista(Lista *lista, int numero);

void agregarACache(Cache * cache, Nodo * nodo);







void imprimirLista(Lista * lista);

#endif //CACHELRU_CACHE_H
