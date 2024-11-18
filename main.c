#include <stdio.h>
#include "functions.h"

#define maxC 30
#define maxP 5

int main (int argc, char *argv[]) {
    int op1, op2, op3, numP;
    char name[maxP][maxC];
    float time[maxP], resources[maxP], maxr;

    storage(&maxr);
    numP=data(name, time, resources);

    do{
        printf("\n");
        printf("Ingrese 1 si desea buscar un producto\n");
        printf("Ingrese 2 si desea chequear la factibilidad de produccion\n");
        printf("Ingrese 3 si desea editar un producto\n");
        printf("Ingrese 4 si desea eliminar un producto\n");
        printf("Ingrese 5 si desea ingresar un producto\n");
        scanf("%d", &op1);
        while (getchar()!='\n');

        switch(op1){
            case 1:
            info(name, time, resources, numP);
            break;
            case 2:
            fact(name, time, resources, &maxr, numP);
            break;
            case 3:
            edition(name, time, resources, numP);
            break;
            case 4:
            deletion(name, time, resources, &numP);
            break;
            case 5:
            productoPlus(name, time, resources, &numP);
            break;
            default:
            printf("Esa no es una opcion valida\n");
            break;
        }
        printf("Desea mostrar todos los productos? presione 1. Si o 2. No\n");
        scanf("%d", &op3);
        while (getchar()!='\n');
        if (op3==1) wholeData(&numP, &maxr, name, time, resources);
        
        printf("Ingrese 1 si desea cerrar el programa o ingrese cualquier tecla para continuar: ");
        op2=getchar();
        while(getchar()!= '\n');

    } while (op2!='1');    

    return 0;
}