#include "Raza.h"
#include <stdio.h>
#include <string.h>
#define OCUPADO 1
#define LIBRE 0

void HardCodeoRaza(sRaza listadoRaza[], int sizeRaza)
{
    int id[20] = {1,2,3,4,5,6,7,8,9,10,11};
    char raza[20][30] = {"Lagarto Overo","Gato Persa","Bengala","Sphynx","Golden retriever","Pitbull","Bulldog","Pastor Aleman","Bengala","San Bernardo","Iguana rayada"};
    char paisRaza[20][30] = {"Argentina","Iran","Estados Unidos","Toronto","Inglaterra","Estados Unidos","Frances","Alemania","Estados Unidos","Italia","Estados Unidos"};

    int i;
    for(i = 0; i<sizeRaza; i++)
    {
        listadoRaza[i].id = id[i];
        strcpy(listadoRaza[i].nombreRaza, raza[i]);
        strcpy(listadoRaza[i].pais, paisRaza[i]);
    }
}
/*
void InicializarRaza(sRaza listadoRaza[], int sizeRaza)
{
    int i;

    for(i = 0; i<sizeRaza; i++)
    {
        listadoRaza[i].isEmpty == OCUPADO;
    }
}
*/
void MostrarRazas(sRaza listadoRaza[], int sizeRaza)
{

    printf("%10s %15s %15s \n","ID RAZA","NOMBRE","PAIS");

    int i;

    for(i = 0; i<sizeRaza; i++)
    {
        MostrarUnaRaza(listadoRaza[i]);
    }
}

void MostrarUnaRaza(sRaza unaRaza)
{
    printf("%10d %15s %15s \n", unaRaza.id,
                                unaRaza.nombreRaza,
                                unaRaza.pais);
}
