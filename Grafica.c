#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo Nodo;

typedef struct Arista{
    Nodo* destino;
    struct Arista* siguiente;
}Arista;

struct Nodo{
    int visitado;
    int dato;
    Arista* adyacentes;
    Nodo* siguiente;
};

typedef struct Grafica {
    Nodo* primero;
} Grafica;

//nomas pa imprimir
void imprimir_grafica(Grafica* g) {
    if (g == NULL || g->primero == NULL) {
        printf("La gráfica está vacía.\n");
        return;
    }

    // 1. Empezamos en el primer nodo de la lista global
    Nodo* nodo_actual = g->primero;

    printf("--- REPRESENTACIÓN DE LA GRÁFICA ---\n");
    
    while (nodo_actual != NULL) {
        // Imprimimos el dato del nodo origen
        printf("Nodo [%d] se conecta con: ", nodo_actual->dato);

        // 2. Recorremos todas las aristas adyacentes de este nodo
        Arista* arista_actual = nodo_actual->adyacentes;
        
        if (arista_actual == NULL) {
            printf("Ninguno (Nodo aislado)");
        }

        while (arista_actual != NULL) {
            // Imprimimos el dato del nodo destino de la arista
            printf("%d ", arista_actual->destino->dato);
            
            // Avanzamos a la siguiente arista de la lista
            arista_actual = arista_actual->siguiente;
        }
        
        printf("\n"); // Salto de línea para el siguiente nodo

        // Avanzamos al siguiente nodo de la lista global de la gráfica
        nodo_actual = nodo_actual->siguiente;
    }
    printf("------------------------------------\n");
}


int main(){
  //Creacion de nodos
    Nodo* nodoA = (Nodo*)malloc(sizeof(Nodo));
    nodoA->dato = 1; nodoA->adyacentes = NULL; nodoA->visitado = 0;
    Nodo* nodoB = (Nodo*)malloc(sizeof(Nodo));
    nodoB->dato = 2; nodoB->adyacentes = NULL; nodoB->visitado = 0;
    Nodo* nodoC = (Nodo*)malloc(sizeof(Nodo));
    nodoC->dato = 3; nodoC->adyacentes = NULL; nodoC->visitado = 0;
    Nodo* nodoD = (Nodo*)malloc(sizeof(Nodo));
    nodoD->dato = 4; nodoD->adyacentes = NULL; nodoD->visitado = 0;
    Nodo* nodoE = (Nodo*)malloc(sizeof(Nodo));
    nodoE->dato = 5; nodoE->adyacentes = NULL; nodoE->visitado = 0;

  //Creacion de grafica
    Grafica grafica;
    grafica.primero = nodoA;
    nodoA->siguiente = nodoB;
    nodoB->siguiente = nodoC;
    nodoC->siguiente = nodoD;
    nodoD->siguiente = nodoE;
    nodoE->siguiente = NULL;

  //Arista A-B
    Arista* deAaB = (Arista*)malloc(sizeof(Arista));
    deAaB->destino = nodoB;
    deAaB->siguiente = nodoA->adyacentes;
    nodoA->adyacentes = deAaB;

    Arista* deBaA = (Arista*)malloc(sizeof(Arista));
    deBaA->destino = nodoA;
    deBaA->siguiente = nodoB->adyacentes;
    nodoB->adyacentes = deBaA;

  //Arista B-C
    Arista* deBaC = (Arista*)malloc(sizeof(Arista));
    deBaC->destino = nodoC;
    deBaC->siguiente = nodoB->adyacentes;
    nodoB->adyacentes = deBaC;

    Arista* deCaB = (Arista*)malloc(sizeof(Arista));
    deCaB->destino = nodoB;
    deCaB->siguiente = nodoC->adyacentes;
    nodoC->adyacentes = deCaB;

  //Arista C-D
    Arista* deCaD = (Arista*)malloc(sizeof(Arista));
    deCaD->destino = nodoD;
    deCaD->siguiente = nodoC->adyacentes;
    nodoC->adyacentes = deCaD;

    Arista* deDaC = (Arista*)malloc(sizeof(Arista));
    deDaC->destino = nodoC;
    deDaC->siguiente = nodoD->adyacentes;
    nodoD->adyacentes = deDaC;

  //Arista C-E
    Arista* deCaE = (Arista*)malloc(sizeof(Arista));
    deCaE->destino = nodoE;
    deCaE->siguiente = nodoC->adyacentes;
    nodoC->adyacentes = deCaE;

    Arista* deEaC = (Arista*)malloc(sizeof(Arista));
    deEaC->destino = nodoC;
    deEaC->siguiente = nodoE->adyacentes;
    nodoE->adyacentes = deEaC;

  //Arista E-D
    Arista* deEaD = (Arista*)malloc(sizeof(Arista));
    deEaD->destino = nodoD;
    deEaD->siguiente = nodoE->adyacentes;
    nodoE->adyacentes = deEaD;

    Arista* deDaE = (Arista*)malloc(sizeof(Arista));
    deDaE->destino = nodoE;
    deDaE->siguiente = nodoD->adyacentes;
    nodoD->adyacentes = deDaE;

    imprimir_grafica(&grafica);
    return 0;
    
}

