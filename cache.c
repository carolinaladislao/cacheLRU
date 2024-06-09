//
// Created by Carol on 8/6/2024.
//

#include <malloc.h>
#include <stdio.h>
#include "cache.h"

Nodo *newNodo(int num) {

    Nodo * aux = malloc (sizeof(Nodo));

    if(aux == NULL){
        printf("No hay espacio en la memoria");
        exit(-1);
    }

    if(num >= TAM){
        printf("\nno se puede insertar, es mayor a %d",TAM);
        return NULL;
    }

    aux->sig = NULL;
    aux->num = num;
    aux->ant = NULL;

    return aux;
}

Lista *newLista() {
    Lista * aux = malloc (sizeof(Lista));

    if(aux == NULL){
        printf("No hay espacio en la memoria");
        exit(-1);
    }

    aux->cabecera = NULL;

    return aux;
}

Cache *newCache(int tam) {
    Cache * aux = malloc(sizeof (Cache));

    if(aux == NULL){
        printf("No hay espacio en la memoria");
        exit(-1);
    }
    aux->ocupacion = 0;
    aux->tamanio = tam;
    aux->cache = newLista();
    for(int i = 0; i < TAM; i++){
        aux->hash[i] = NULL;
    }

    return aux;
}

void insertarNodoListaApilando(Lista *lista, Nodo *nodo) {

    if(nodo != NULL){
        if (lista->cabecera != NULL){
            lista->cabecera->ant = nodo;
        }
        nodo->sig = lista->cabecera;
        lista->cabecera = nodo;
    }

}

void imprimirLista(Lista *lista) {
    Nodo * aux = lista->cabecera;

    printf("\nImpresion:");

    for (; aux != NULL; aux = aux->sig){
        printf(" %d ",aux->num);
    }
}

void solicitarNumero(Cache * cache, Lista *lista, int numero) {
    Nodo * elemento = cache->hash[numero];
    if(elemento != NULL){
        //entonces el numero esta en la cache
        if(cache->cache->cabecera != elemento){
            desasociarElemento(elemento);
            agregarACache(cache, elemento);
        }
        //en este caso no le sumo al contador de la cache, porque el elemento ya estaba
    }else{
        //camin largo, el numero no esta en la cache
        if (buscarNumeroEnLista(lista,numero) == 1){//encontro el numero en la lista
            elemento = newNodo(numero);
            if(cache->ocupacion == cache->tamanio){
                hacerEspacioEnCache(cache);
            }
            agregarACache(cache,elemento);
            cache->ocupacion++;
        }
        else{
            printf("\nNo se pudo solicitar el numero %d porque no esta en la lista principal",numero);
        }
    }

}

void desasociarElemento(Nodo *nodo) {

    if(nodo->ant != NULL){
        nodo->ant->sig = nodo->sig;
    }
    if(nodo->sig != NULL){
        nodo->sig->ant = nodo->ant;
    }
    nodo->ant = NULL;
    nodo->sig =NULL;
}

void agregarACache(Cache *cache, Nodo *nodo) {

    insertarNodoListaApilando(cache->cache, nodo);
    cache->hash[nodo->num] = nodo;


}

void hacerEspacioEnCache(Cache *cache) {
    Nodo * aux = cache->cache->cabecera;

    for(;aux->sig != NULL; aux = aux->sig){}

    aux->ant->sig = NULL;

    cache->hash[aux->num] = NULL;

    cache->ocupacion--;

    free(aux);

}

int buscarNumeroEnLista(Lista *lista, int numero) {
    Nodo * aux = lista->cabecera;

    for(; aux != NULL; aux = aux->sig){
        if(aux->num == numero){
            return 1;
        }
    }

    return 0;
}
