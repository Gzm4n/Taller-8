#include <stdio.h>
#include <string.h>

#define maxC 30
#define maxP 5

void storage(float *max){
    float q;
    printf("Escriba la cantidad de prespuesto ($) disponible para un mes: ");
    scanf("%f", &q);
    *max=q;
    while (getchar()!='\n');
}

int data(char name[maxP][maxC], float time[maxP], float rec[maxP]){
    int c;
    printf("Ingrese la cantidad de productos que desea ingresar: ");
    scanf("%d", &c);
    while (getchar()!='\n');
    printf("Recuerde, los productos a ingresar son %d, con un maximo de 30 caracteres\n", c);
    for (int i=0; i<c; i++){
        printf("Ingrese el nombre del producto %d: ", i+1);
        fgets(name[i], maxC, stdin);
        name[i][strcspn(name[i], "\n")]='\0';

        printf("Ingrese el tiempo que requiere su produccion en horas: ");
        scanf("%f", &time[i]);

        printf("Ingrese la cantidad de recursos economicos que necesita el producto ($): ");
        scanf("%f", &rec[i]);

        while(getchar()!='\n');
    }
    return c;
}

int search(char id[maxC], char name[maxP][maxC], int numP){
    for (int i=0; i<numP; i++){
        if (strcmp(id, name[i])==0){ 
            return i;
        }
    }
    return -1;
}

void info(char name[maxP][maxC], float time[maxP], float rec[maxP], int numP){
    char id[maxC];
    int aux;
    printf("Ingrese el producto que desea buscar: ");
    fgets(id, maxC, stdin);
    id[strcspn(id, "\n")]='\0';

    aux=search(id,name, numP);
    if (aux!=-1){
        printf("El producto es %s\n", name[aux]);
        printf("Tiempo de produccion: %.2f\n", time[aux]);
        printf("Presupuesto necesario: %.2f\n", rec[aux]);
    }
    else printf("Producto no encontrado\n");
}

void fact(char name[maxP][maxC], float time[maxP], float rec[maxP], float *max, int numP){
    char id[maxC];
    int q=0, op;
    float t=0, rn, tn;
    printf("Ingrese el nombre del producto: ");
    fgets(id, maxC, stdin);
    id[strcspn(id, "\n")]='\0';

    printf("Ingrese la cantidad que se desea producir: ");
    scanf("%d", &q);

    printf("Ingrese el tiempo (en horas) en el que se debe producir: ");
    scanf("%f", &t);

    while (getchar()!='\n');

    int aux=search(id, name, numP);
    if (aux!=-1){
        rn=rec[aux]*q;
        tn=time[aux]*q;
        if (rn<= *max && tn<=t && t<=530){
            printf("El tiempo y recursos economicos permiten la produccion\n");
            printf("Presupuesto necesario: %.2f$. Tiempo necesario: %.2f\n", rn, tn);
            printf("Desea restar del presupuesto general? Ingrese: 1.Si 2.No\n");
            scanf("%d", &op);
            while (getchar()!='\n');

            if (op==1){
                *max= *max - rn;
                printf("El total de presupuesto restante es: %.2f\n", *max);
            }
        }
        else{
            printf("El tiempo o los recursos economicos NO permiten la produccion\n");
            printf("Presupuesto necesario: %.2f$. Tiempo necesario: %.2f\n", rn, tn);
            printf("Presupuesto disponible: %.2f$. Tiempo disponible: %.2f\n", *max, t);
        }
    }
    else printf("Producto no encontrado\n");
}

void edition(char name[maxP][maxC], float time[maxP], float rec[maxP], int numP){
    char id[maxC];
    int op;
    printf("Ingrese el nombre del producto que desea editar: ");
    fgets(id, maxC, stdin);
    id[strcspn(id, "\n")]='\0';
    int aux=search(id, name, numP);
    if(aux!=-1){
        printf("Ingrese 1 para editar el nombre, 2 para editar los recursos economicos ($) o 3 para editar el tiempo: ");
        scanf("%d", &op);
        while(getchar()!='\n');
        switch(op){
            case 1:
            printf("Ingrese el nuevo nombre del producto: ");
            fgets(name[aux], maxC, stdin);
            name[aux][strcspn(name[aux], "\n")]='\0';
            printf("El producto ahora se llama: %s\n", name[aux]);
            break;
            case 2:
            printf("Ingrese la cantidad de presupuesto nueva: ");
            scanf("&f", &rec[aux]);
            printf("La cantidad nueva es: %.2f\n", rec[aux]);
            break;
            case 3:
            printf("Ingrese el tiempo (en horas) nuevo: ");
            scanf("%f", &time[aux]);
            printf("La cantidad nueva es: %.2f\n", time[aux]);
            break;
            default:
            printf("Esa no es una opcion valida");
            break;
        }
    }
    else printf("Producto no encontrado\n");
}

void deletion(char name[maxP][maxC], float time[maxP], float rec[maxP], int *numP){
    char id[maxC];
    printf("Ingrese el nombre del producto que desea eliminar: ");
    fgets(id, maxC, stdin);
    id[strcspn(id, "\n")]='\0';
    int aux=search(id, name, *numP);
    if(aux!=-1){
        for(int i=aux; i<*numP-1; i++){
            strcpy(name[i], name[i+1]);
            time[i]=time[i+1];
            rec[i]=rec[i+1];
        }
        printf("Producto eliminado con exito\n");
    }
    else printf("Producto no encontrado\n");
    *numP-=1;
}

void productoPlus(char name [maxP][maxC], float time [maxP], float rec[maxP], int *numP){
    printf("Ingrese el nombre del producto %d: ", *numP+1);
    fgets(name[*numP], maxC, stdin);
    name[*numP][strcspn(name[*numP], "\n")]='\0';

    printf("Ingrese el tiempo que requiere su produccion en horas: ");
    scanf("%f", &time[*numP]);

    printf("Ingrese la cantidad de recursos economicos que necesita el producto ($): ");
    scanf("%f", &rec[*numP]);

    while(getchar()!='\n');
    *numP+=1;
}

void wholeData(int *numP, float *max, char name[maxP][maxC], float time[maxP], float rec[maxP]){
    printf("El total de productos es %d, con un presupuesto final de: %.2f\n", *numP, *max);
    printf("--------------------------------------------------------------------------\n");
    for (int i=0; i<*numP; i++){
        printf("El producto %s se produce con %.2f USD en %.2f horas.\n", name[i], rec[i], time[i]);
    }
}
