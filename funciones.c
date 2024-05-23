#include <stdio.h>
#include "funciones.h"
#include <string.h>

int buscarXNombre(char nombres[][2][40], int n, char nombre[]){
    int index=-1;
    for (int i = 0; i < n; i++)
    {
        if(strcmp(nombres[i][0],nombre)==0){
            index=i;
            break;
        }
    }
    return index;
}

void imprimirNumero(char nombres[][2][40], int numeros[], int index){
    printf("El numero de %s es %d y su direcciones %s\n",nombres[index][0],
                                                       numeros[index],
                                                       nombres[index][1]);
}

void imprimirContactos(char nombres[][2][40], int numeros[], int n){
    printf("Nombre\t\tNumero\t\tDireccion\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%s\n",nombres[i][0],numeros[i],nombres[i][1]);
    }
}

void ingresarContacto(char nombres[][2][40], int numeros[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el nombre del contacto %d: ",i);
        scanf("%s",&nombres[i][0]);
        printf("Ingrese el numero del contacto %d: ",i);
        scanf("%d",&numeros[i]);
        printf("Ingrese la direccion del contacto %d: ",i);
        scanf("%s",&nombres[i][1]);
    } 
}

void editarContacto(char nombres[][2][40], 
                    int numeros[]){
            char nuevaDireccion[40], nombreABuscar[40];
            int nuevoNumero;
            printf("Ingrese el nombre del contacto que desa editar: ");
            fflush(stdin);
            scanf("%s",&nombreABuscar);
            int index = buscarXNombre(nombres,6,nombreABuscar);
            if (index!=-1){
                printf("Ingrese la nueva direccion del contacto: ");
                fflush(stdin);
                scanf("%s",&nuevaDireccion);
                printf("Ingrese el nuevo numero del contacto: ");
                fflush(stdin);
                scanf("%d",&nuevoNumero);
                strcpy(nombres[index][1],nuevaDireccion);
                numeros[index]=nuevoNumero;
            }else{
                printf("El nombre buscado no existe");
            }       
}