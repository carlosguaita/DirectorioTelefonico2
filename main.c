#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    char nombresDireccion[6][2][40]={{"luis","nayon"},
                                     {"ana","marin"},
                                     {"jose","tejar"},
                                     {"lorena","carcelen"},
                                     {"juan","inca"},
                                     {"maria","recreo"}};

    int numeros[6]={245,345,456,567,678,789};

    char nombreABuscar[40];

    imprimirContactos(nombresDireccion,numeros,6);
    ingresarContacto(nombresDireccion,numeros,3);
    imprimirContactos(nombresDireccion,numeros,6);
    printf("Ingrese el nombre a buscar: ");
    fflush(stdin);
    scanf("%s",&nombreABuscar);

    int index = buscarXNombre(nombresDireccion,6,nombreABuscar);
    if (index!=-1){
        imprimirNumero(nombresDireccion,numeros,index);
    }else{
        printf("El nombre buscado no existe");
    }



    return 0;
}