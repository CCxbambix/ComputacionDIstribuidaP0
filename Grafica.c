#include <stdio.h>
#include <stdlib.h>

/*Implementación de gráfica*/
typedef struct Nodo Nodo;
/*Arista de la grafica */
typedef struct Arista{
    int visited;
    Nodo* destino;
    struct Arista* siguiente;
}Arista;

/*Nodo de la grafica, tambien es usado este Nodo para
la estructura de Cola y Pila */
struct Nodo{
    int visitado;
    int dato;
    int numAristas;
    Arista* adyacentes;
    Nodo* siguiente;
    Nodo* datos;
};

/*Grafica*/
typedef struct Grafica {
    Nodo* primero;
} Grafica;

/*Implementacion de pila */
typedef struct
{
    Nodo *tope;
} Pila;

void inicializarPila(Pila *p)
{
    p->tope = NULL;
}

int pilaVacia(Pila *p)
{
    return p->tope == NULL;
}

void push(Pila *p, Nodo* dato)
{
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL)
    {
        printf("Error reservando memoria\n");
        return;
    }

    nuevo->datos = dato;
    nuevo->siguiente = p->tope;

    p->tope = nuevo;
}

Nodo* pop(Pila *p)
{
    if (pilaVacia(p))
    {
        printf("La pila está vacía\n");
        return NULL;
    }

    Nodo *temp = p->tope;

    Nodo *dato = temp->datos;

    p->tope = temp->siguiente;

    //free(temp);

    return dato;
}

void imprimirPila(Pila *p)
{
    Nodo *actual = p->tope;
    printf("Pila: ");
    while (actual != NULL)
    {
        Nodo *nodoActual = actual->datos;
        printf("%d ", nodoActual->dato);
        actual = actual->siguiente;
    }

    printf("\n");
}

/* Implementación de Cola */

typedef struct
{
    Nodo *frente;
    Nodo *final;
} Cola;

void inicializarCola(Cola *c)
{
    c->frente = NULL;
    c->final = NULL;
}

int colaVacia(Cola *c)
{
    return c->frente == NULL;
}

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

Nodo* dequeue(Cola *c)
{
    if (colaVacia(c))
    {
        printf("La cola está vacía\n");
        return NULL;
    }

    Nodo *temp = c->frente;

    Nodo *dato = temp->datos;

    c->frente = temp->siguiente;

    if (c->frente == NULL)
    {
        c->final = NULL;
    }

    /*free(temp);*/

    return dato;
}

void imprimirCola(Cola *c)
{
    Nodo *actual = c->frente;
    printf("Cola: ");
    while (actual != NULL)
    {
        Nodo *nodoActual = actual->datos;
        printf("%d ", nodoActual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void BFS(Grafica* g){
    Cola cola;
    inicializarCola(&cola);
    Nodo *first = g->primero;
    first->visitado=1;
    printf("%d\n",first->dato);
    enqueue(&cola,first);
    while (0==colaVacia(&cola)){
        Nodo *c = cola.frente;
        Nodo *v = c->datos;
        dequeue(&cola);
        Arista *aristaActual = v->adyacentes;
        for(int i=1;i<=v->numAristas;i++){
          if(0==aristaActual->visited){
            aristaActual->visited = 1;
            Nodo *w = aristaActual->destino;
            if(0==w->visitado){
              printf("%d\n",w->dato);
              enqueue(&cola,w);
              w->visitado =1;
            }
          }
          aristaActual = aristaActual->siguiente;
        }
    }
}

void DFS(Nodo* primero){
    printf("%d\n",primero->dato);
    primero->visitado=1;
    Arista *e = primero->adyacentes;
    for(int i=1; i<=primero->numAristas;i++){
        if(0==e->visited){
            e->visited = 1;
            Nodo *w = e->destino;
            if(0==w->visitado){
                DFS(w);
            }
        }
        e= e->siguiente;
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

    /*Segunda grafica*/
    Nodo* nodoF = (Nodo*)malloc(sizeof(Nodo));
    nodoF->dato = 6; nodoF->adyacentes = NULL; nodoF->visitado = 0;
    Nodo* nodoG = (Nodo*)malloc(sizeof(Nodo));
    nodoG->dato = 7; nodoG->adyacentes = NULL; nodoG->visitado = 0;
    Nodo* nodoH = (Nodo*)malloc(sizeof(Nodo));
    nodoH->dato = 8; nodoH->adyacentes = NULL; nodoH->visitado = 0;
    Nodo* nodoI = (Nodo*)malloc(sizeof(Nodo));
    nodoI->dato = 9; nodoI->adyacentes = NULL; nodoI->visitado = 0;
    Nodo* nodoJ = (Nodo*)malloc(sizeof(Nodo));
    nodoJ->dato = 10; nodoJ->adyacentes = NULL; nodoJ->visitado = 0;

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

    /*Segunda grafica*/
    nodoF->siguiente = nodoG;
    nodoG->siguiente = nodoH;
    nodoH->siguiente = nodoI;
    nodoI->siguiente = nodoJ;
    nodoJ->siguiente = NULL;
    nodoF->numAristas = 1;
    nodoG->numAristas = 2;
    nodoH->numAristas = 3;
    nodoI->numAristas = 2;
    nodoJ->numAristas = 2;

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

    /*Segunda grafica*/
    //Arista F-G
    Arista* deFaG = (Arista*)malloc(sizeof(Arista));
    deFaG->visited = 0;
    deFaG->destino = nodoG;
    deFaG->siguiente = nodoF->adyacentes;
    nodoF->adyacentes = deFaG;

    Arista* deGaF = (Arista*)malloc(sizeof(Arista));
    deGaF->visited = 0;
    deGaF->destino = nodoF;
    deGaF->siguiente = nodoG->adyacentes;
    nodoG->adyacentes = deGaF;

  //Arista G-H
    Arista* deGaH = (Arista*)malloc(sizeof(Arista));
    deGaH->visited = 0;
    deGaH->destino = nodoH;
    deGaH->siguiente = nodoG->adyacentes;
    nodoG->adyacentes = deGaH;

    Arista* deHaG = (Arista*)malloc(sizeof(Arista));
    deHaG->visited=0;
    deHaG->destino = nodoG;
    deHaG->siguiente = nodoH->adyacentes;
    nodoH->adyacentes = deHaG;

  //Arista H-I
    Arista* deHaI = (Arista*)malloc(sizeof(Arista));
    deHaI->visited=0;
    deHaI->destino = nodoI;
    deHaI->siguiente = nodoH->adyacentes;
    nodoH->adyacentes = deHaI;

    Arista* deIaH = (Arista*)malloc(sizeof(Arista));
    deIaH->visited=0;
    deIaH->destino = nodoH;
    deIaH->siguiente = nodoI->adyacentes;
    nodoI->adyacentes = deIaH;

  //Arista H-J
    Arista* deHaJ = (Arista*)malloc(sizeof(Arista));
    deHaJ->visited=0;
    deHaJ->destino = nodoJ;
    deHaJ->siguiente = nodoH->adyacentes;
    nodoH->adyacentes = deHaJ;

    Arista* deJaH = (Arista*)malloc(sizeof(Arista));
    deJaH->visited=0;
    deJaH->destino = nodoH;
    deJaH->siguiente = nodoJ->adyacentes;
    nodoJ->adyacentes = deJaH;

  //Arista J-I
    Arista* deJaI = (Arista*)malloc(sizeof(Arista));
    deJaI->visited=0;
    deJaI->destino = nodoI;
    deJaI->siguiente = nodoJ->adyacentes;
    nodoJ->adyacentes = deJaI;

    Arista* deIaJ = (Arista*)malloc(sizeof(Arista));
    deIaJ->visited=0;
    deIaJ->destino = nodoJ;
    deIaJ->siguiente = nodoI->adyacentes;
    nodoI->adyacentes = deIaJ;

    /*Creacion de Pila para su prueba*/
    Pila pila;
    inicializarPila(&pila);
    Nodo* nodoP1 = (Nodo*)malloc(sizeof(Nodo));
    nodoP1->dato = 11;
    Nodo* nodoP2 = (Nodo*)malloc(sizeof(Nodo));
    nodoP2->dato = 12;
    Nodo* nodoP3 = (Nodo*)malloc(sizeof(Nodo));
    nodoP3->dato = 13;

    Cola cola;
    inicializarCola(&cola);
    Nodo* nodoC1 = (Nodo*)malloc(sizeof(Nodo));
    nodoC1->dato = 14;
    Nodo* nodoC2 = (Nodo*)malloc(sizeof(Nodo));
    nodoC2->dato = 15;
    Nodo* nodoC3 = (Nodo*)malloc(sizeof(Nodo));
    nodoC3->dato = 16;

    /*Ejecucion de los metodos, por favor comente la funcion que no usara para probar la otra*/
    printf("Ejecucion de BFS\n");
    BFS(&grafica);
    printf("Ejecucion de DFS\n");
    DFS(nodoF);
    printf("Prueba de Pila\n");
    printf("Pila Vacia\n");
    printf("%d\n", pilaVacia(&pila));
    printf("Metemos elementos a la pila\n");
    push(&pila,nodoP1);
    push(&pila,nodoP2);
    push(&pila,nodoP3);
    printf("Pila no vacia\n");
    printf("%d\n", pilaVacia(&pila));
    printf("Imprimimos la Pila\n");
    imprimirPila(&pila);
    printf("sacamos un elemento de la pila\n");
    pop(&pila);
    imprimirPila(&pila);
    printf("Prueba de Cola\n");
    printf("Cola Vacia\n");
    printf("%d\n", colaVacia(&cola));
    printf("Metemos elementos a la cola\n");
    enqueue(&cola,nodoC1);
    enqueue(&cola,nodoC2);
    enqueue(&cola,nodoC3);
    printf("Cola no vacia\n");
    printf("%d\n", colaVacia(&cola));
    printf("Imprimimos la Cola\n");
    imprimirCola(&cola);
    printf("sacamos un elemento de la Cola\n");
    dequeue(&cola);
    imprimirCola(&cola);
    
    




    return 0;
    
}

