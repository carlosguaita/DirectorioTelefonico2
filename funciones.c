#include <stdio.h>
#include "funciones.h"
#include <string.h>

void buscarContacto(char nombres[][2][40], int numeros[], int edad[], int n){
    char nombreABuscar[40];
    int indices[6]={-1,-1,-1,-1,-1,-1};
    int noexiste=0;
    printf("Ingrese el nombre a buscar: ");
    fflush(stdin);
    scanf("%s",&nombreABuscar);
    buscarNombres(nombres,n,nombreABuscar,indices);
    for (int i = 0; i < n; i++){
        if(indices[i]!=-1){
          imprimirNumero(nombres,numeros,edad,indices[i]);
          noexiste=1;
        }        
    }
    if(noexiste==0){
       printf("El nombre buscado no existe\n");
    }
}

void buscarContactoXEdad(char nombres[][2][40], int numeros[], int edad[], int n){
    int edadABuscar;
    int indices[6]={-1,-1,-1,-1,-1,-1};
    int noexiste=0;
    printf("Ingrese la edad de los contactos a buscar: ");
    fflush(stdin);
    scanf("%d",&edadABuscar);
    buscarEdades(edad,6,edadABuscar,indices);
    for (int i = 0; i < n; i++){
        if(indices[i]!=-1){
          imprimirNumero(nombres,numeros,edad,indices[i]);
          noexiste=1;
        }        
    }
    if(noexiste==0){
       printf("El nombre buscado no existe\n");
    }
}


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

void buscarNombres(char nombres[][2][40], int n, char nombre[], int indices[]){
    int j=0;
    for (int i = 0; i < n; i++)
    {
        if(strcmp(nombres[i][0],nombre)==0){
            indices[j]=i;
            j++;
        }
    }
}

void buscarEdades(int edades[], int n, int edad, int indices[]){
    int j=0;
    for (int i = 0; i < n; i++)
    {
        if(edades[i]==edad){
            indices[j]=i;
            j++;
        }
    }
}


void imprimirNumero(char nombres[][2][40], int numeros[], int edad[], int index){
    printf("El numero de %s es %d, su direccion es %s y su edad es %d\n",nombres[index][0],
                                                       numeros[index],
                                                       nombres[index][1],
                                                       edad[index]);
}

void imprimirContactos(char nombres[][2][40], int numeros[], int edad[], int n){
    printf("Nombre\t\tNumero\t\tDireccion\t\tEdad\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%s\t\t%d\n",nombres[i][0],numeros[i],nombres[i][1],edad[i]);
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

void editarContacto(char nombres[][2][40],int numeros[]){
            char nuevaDireccion[40], nombreABuscar[40];
            int nuevoNumero;
            printf("Ingrese el nombre del contacto que desea editar: ");
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