#include <stdio.h>

typedef struct Vertice
{
    int visitado;
    int dato;
    struct Vertice*siguientes[2];
}Vertice;

int main(){

    struct Vertice v1;
    struct Vertice v2;
    struct Vertice v3;
    struct Vertice v4;
    struct Vertice v5;

    v1.dato = 1;
    v2.dato = 2;
    v3.dato = 3;
    v4.dato = 4;
    v5.dato = 5;

    v1.siguientes[0] = &v2;
    v1.siguientes[1] = &v3;

    struct Vertice *vTemp = &v1;
    printf("%d\n",vTemp->dato);
    vTemp = v1.siguientes[0];
    printf("%d\n",vTemp->dato);
    vTemp = v1.siguientes[1];
    printf("%d\n",vTemp->dato);

    return 0;
    
}

