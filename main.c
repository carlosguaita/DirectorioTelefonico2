#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    char nombresDireccion[6][2][40]={{"luis","nayon"},
                                     {"ana","marin"},
                                     {"jose","tejar"},
                                     {"lorena","carcelen"},
                                     {"juan","inca"},
                                     {"maria","recreo"}};
    int edades[6]={20,40,35,30,20,24};
    int numeros[6]={245,345,456,567,678,789};
    char nombreABuscar[40];
    int opcion1, opcion2;
    do{

        printf("Selecciones una opcion:\n1.Ingresar Contactos\n2.MostrarContactos\n3.Buscar Contacto\n4.Editar Contacto\n>>");
        scanf("%d",&opcion1);
        switch (opcion1)
        {
        case 1:
            ingresarContacto(nombresDireccion,numeros,6);
            break;
        case 2:
            imprimirContactos(nombresDireccion,numeros,edades,6);
            break;
        case 3:
            buscarContacto(nombresDireccion,numeros,edades,6);
            break;
        case 4:
            editarContacto(nombresDireccion,numeros);
            break;
        default:
            break;
        }

    printf("Desea seleccionar otra opcion: 1.Si / 2.No\n>>");
    scanf("%d",&opcion2);
    }while(opcion2==1);

    return 0;
}