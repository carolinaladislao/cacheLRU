#include <stdio.h>
#include "cache.h"

int main() {
    Lista * lista = newLista();
    Cache * cache = newCache(5);

    insertarNodoListaApilando(lista,newNodo(30));
    insertarNodoListaApilando(lista,newNodo(200));
    insertarNodoListaApilando(lista,newNodo(5));
    insertarNodoListaApilando(lista,newNodo(10));
    insertarNodoListaApilando(lista,newNodo(20));
    insertarNodoListaApilando(lista,newNodo(90));
    insertarNodoListaApilando(lista,newNodo(110));
    insertarNodoListaApilando(lista,newNodo(100));

    solicitarNumero(cache,lista,30);
    solicitarNumero(cache,lista,40);
    solicitarNumero(cache,lista,5);


    imprimirLista(cache->cache); // 5 40 30

    solicitarNumero(cache,lista,90);
    solicitarNumero(cache,lista,40);
    solicitarNumero(cache,lista,110);

    imprimirLista(cache->cache);

    solicitarNumero(cache,lista,30);
    solicitarNumero(cache,lista,100);

    imprimirLista(cache->cache);


    printf("\nLa lista es:");
    imprimirLista(lista);

    solicitarNumero(cache,lista,10);
    imprimirLista(cache->cache);//

    solicitarNumero(cache,lista,10);
    solicitarNumero(cache,lista,20);
    solicitarNumero(cache,lista,10);
    return 0;
}
