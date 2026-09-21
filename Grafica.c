#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo Nodo;

typedef struct Arista{
    int visited;
    Nodo* destino;
    struct Arista* siguiente;
}Arista;

struct Nodo{
    int visitado;
    int dato;
    int numAristas;
    Arista* adyacentes;
    Nodo* siguiente;
    Nodo* datos;
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

/* =========================
   COLA
   ========================= */

typedef struct
{
    Nodo *frente;
    Nodo *final;
} Cola;


/* Inicializa la cola */
void inicializarCola(Cola *c)
{
    c->frente = NULL;
    c->final = NULL;
}


/* Verifica si esta vacia */
int colaVacia(Cola *c)
{
    return c->frente == NULL;
}

/* ENQUEUE */
void enqueue(Cola *c, Nodo* dato)
{
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL)
    {
        printf("Error reservando memoria\n");
        return;
    }

    nuevo->datos = dato;
    nuevo->siguiente = NULL;

    if (colaVacia(c))
    {
        c->frente = nuevo;
        c->final = nuevo;
    }
    else
    {
        c->final->siguiente = nuevo;
        c->final = nuevo;
    }
}


/* DEQUEUE */
Nodo* dequeue(Cola *c)
{
    if (colaVacia(c))
    {
        printf("La cola está vacía\n");
        return NULL;
    }

    Nodo *temp = c->frente;

    Nodo* dato = temp->datos;

    c->frente = temp->siguiente;

    if (c->frente == NULL)
    {
        c->final = NULL;
    }

    /*free(temp);*/

    return dato;
}

void BFS(Grafica *g){
    Cola cola;
    inicializarCola(&cola);
    Nodo *first = g->primero;
    first->visitado=1;
    enqueue(&cola,first);
    while (1==colaVacia(&cola)){
        Nodo *v = cola.frente;
        dequeue(&cola);
        Arista *aristaActual = v->adyacentes;
        for(int i=1;i<=v->numAristas;i++){
          if(0==aristaActual->visited){
            aristaActual->visited = 1;
            Nodo *w = aristaActual->destino;
            if(0==w->visitado){
              printf("%d",w->dato);
              enqueue(&cola,w);
              w->visitado =1;
            }
          }
          aristaActual = aristaActual->siguiente;
        }
    }
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
    nodoA->numAristas = 1;
    nodoB->numAristas = 2;
    nodoC->numAristas = 3;
    nodoD->numAristas = 2;
    nodoE->numAristas = 2;

  //Arista A-B
    Arista* deAaB = (Arista*)malloc(sizeof(Arista));
    deAaB->visited = 0;
    deAaB->destino = nodoB;
    deAaB->siguiente = nodoA->adyacentes;
    nodoA->adyacentes = deAaB;

    Arista* deBaA = (Arista*)malloc(sizeof(Arista));
    deBaA->visited = 0;
    deBaA->destino = nodoA;
    deBaA->siguiente = nodoB->adyacentes;
    nodoB->adyacentes = deBaA;

  //Arista B-C
    Arista* deBaC = (Arista*)malloc(sizeof(Arista));
    deBaC->visited = 0;
    deBaC->destino = nodoC;
    deBaC->siguiente = nodoB->adyacentes;
    nodoB->adyacentes = deBaC;

    Arista* deCaB = (Arista*)malloc(sizeof(Arista));
    deCaB->visited=0;
    deCaB->destino = nodoB;
    deCaB->siguiente = nodoC->adyacentes;
    nodoC->adyacentes = deCaB;

  //Arista C-D
    Arista* deCaD = (Arista*)malloc(sizeof(Arista));
    deCaD->visited=0;
    deCaD->destino = nodoD;
    deCaD->siguiente = nodoC->adyacentes;
    nodoC->adyacentes = deCaD;

    Arista* deDaC = (Arista*)malloc(sizeof(Arista));
    deDaC->visited=0;
    deDaC->destino = nodoC;
    deDaC->siguiente = nodoD->adyacentes;
    nodoD->adyacentes = deDaC;

  //Arista C-E
    Arista* deCaE = (Arista*)malloc(sizeof(Arista));
    deCaE->visited=0;
    deCaE->destino = nodoE;
    deCaE->siguiente = nodoC->adyacentes;
    nodoC->adyacentes = deCaE;

    Arista* deEaC = (Arista*)malloc(sizeof(Arista));
    deEaC->visited=0;
    deEaC->destino = nodoC;
    deEaC->siguiente = nodoE->adyacentes;
    nodoE->adyacentes = deEaC;

  //Arista E-D
    Arista* deEaD = (Arista*)malloc(sizeof(Arista));
    deEaD->visited=0;
    deEaD->destino = nodoD;
    deEaD->siguiente = nodoE->adyacentes;
    nodoE->adyacentes = deEaD;

    Arista* deDaE = (Arista*)malloc(sizeof(Arista));
    deDaE->visited=0;
    deDaE->destino = nodoE;
    deDaE->siguiente = nodoD->adyacentes;
    nodoD->adyacentes = deDaE;

    /*imprimir_grafica(&grafica);*/
    BFS(&grafica);
    return 0;
    
}

