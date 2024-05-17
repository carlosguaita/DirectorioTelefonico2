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
    printf("El numero de %s es %d y su direcciones %s",nombres[index][0],
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
    printf("Ingrese el nombre: ");
    scanf("%s",&nombres[n][0]);
    printf("Ingrese el numero: ");
    scanf("%d",&numeros[n]);
    printf("Ingrese la direccion: ");
    scanf("%s",&nombres[n][1]);
}