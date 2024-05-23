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
    int opcion1, opcion2;
    do{

        printf("Selecciones una opcion:\n1.Ingresar Contactos\n2.MostrarContactos\n3.BuscarContacto\n4.Editar Contacto\n>>");
        scanf("%d",&opcion1);
        switch (opcion1)
        {
        case 1:
            ingresarContacto(nombresDireccion,numeros,6);
            break;
        case 2:
            imprimirContactos(nombresDireccion,numeros,6);
            break;
        case 3:
            printf("Ingrese el nombre a buscar: ");
            fflush(stdin);
            scanf("%s",&nombreABuscar);
            int index = buscarXNombre(nombresDireccion,6,nombreABuscar);
            if (index!=-1){
                imprimirNumero(nombresDireccion,numeros,index);
            }else{
                printf("El nombre buscado no existe\n");
            }
            break;
        case 4:
            char nuevaDireccion[40];
            int nuevoNumero;
            printf("Ingrese el nombre del contacto que desa editar: ");
            fflush(stdin);
            scanf("%s",&nombreABuscar);
            int index2 = buscarXNombre(nombresDireccion,6,nombreABuscar);
            if (index2!=-1){
                printf("Ingrese la nueva direccion del contacto: ");
                fflush(stdin);
                scanf("%s",&nuevaDireccion);
                printf("Ingrese el nuevo numero del contacto: ");
                fflush(stdin);
                scanf("%d",&nuevoNumero);
                editarContacto(nombresDireccion,numeros,nuevaDireccion,nuevoNumero,index2);
            }else{
                printf("El nombre buscado no existe");
            }
            break;
        default:
            break;
        }

    printf("Desea seleccionar otra opcion: 1.Si / 2.No\n>>");
    scanf("%d",&opcion2);
    }while(opcion2==1);
    
    return 0;
}