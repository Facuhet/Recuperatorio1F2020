#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mascotas.h"
#include "Gets.h"
#define OCUPADO 1
#define LIBRE 0

void HardcodeoMascotas(sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;

    int id[20] = {100,101,102,103,104,105,106,107,108,109,110};
    char nombre[20][30] = {"GatoUNO","GatoDOS","GatoTRES","GatoCUATRO","PerroUNO","PerroDOS","PerroTRES","PerroCUATRO","GatoCINCO","PerroCINCO","IguanaUNO"};
    char tipo[20][30] = {"Gato","Gato","Gato","Gato","Perro","Perro","Perro","Perro","Gato","Perro","Raro"};
    int raza[20] = {1,2,3,4,5,6,7,8,9,10,11,11};
    int edad[20] = {5,5,6,7,9,3,7,8,3,3,3};
    float peso[20] = {5.000,6.100,7.600,8.200,9.500,4.120,9.300,10.100,9.300,6.200,5.700};
    char sexo[20][10] = {"Hembra","Hembra","Macho","Macho","Macho","Macho","Macho","Hembra","Macho","Macho","Hembra"};
    int idCliente[20] = {100,100,104,104,101,103,104,102,102,102,103};
    int isEmpty[20] = {OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

    //{"Persa","Siames","Bengala","Sphynx","Labrador","Pitbull","Bulldog","Caniche","Persa","Bulldog","Iguana"};

    for(i = 0; i<sizeMascotas; i++)
    {
        listadoMascotas[i].id = id[i];
        strcpy(listadoMascotas[i].nombre, nombre[i]);
        strcpy(listadoMascotas[i].tipo, tipo[i]);
        listadoMascotas[i].idRaza = raza[i];
        listadoMascotas[i].edad = edad[i];
        listadoMascotas[i].peso = peso[i];
        strcpy(listadoMascotas[i].sexo, sexo[i]);
        listadoMascotas[i].idCliente = idCliente[i];
        listadoMascotas[i].isEmpty = isEmpty[i];
    }
}

void InicializarMascotas(sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;

    for(i=0; i<sizeMascotas; i++)
    {
        listadoMascotas[i].isEmpty = LIBRE;
    }
}

int BuscarMascotaLibre(sMascotas listadoMascota[], int sizeMascotas)
{
    int i;
    int indice;

    indice = -1;

    for(i=0; i<sizeMascotas; i++)
    {
        if(listadoMascota[i].isEmpty == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void MostrarUnaMascota(sMascotas unaMascota, sRaza unaRaza)
{
    printf("%15d %15s %18s %18s %18s %10d %10.3f %10s \n",   unaMascota.id,
                                                        unaMascota.nombre,
                                                        unaMascota.tipo,
                                                        unaRaza.nombreRaza,
                                                        unaRaza.pais,
                                                        unaMascota.edad,
                                                        unaMascota.peso,
                                                        unaMascota.sexo);
}

void MostrarListadoSoloMascotas(sMascotas listadoMascotas[], int sizeMascotas, sRaza listadoRazas[], int sizeRazas)
{
    int i;
    int j;

    printf("%15s %15s %18s %18s %18s %10s %10s %10s \n","ID","NOMBRE","TIPO","RAZA","RAZA PAIS","EDAD","PESO","SEXO");
    for(i=0; i<sizeMascotas; i++)
    {
        for(j=0; j<sizeRazas; j++)
        {
            if(listadoMascotas[i].isEmpty == OCUPADO && listadoMascotas[i].idRaza == listadoRazas[j].id)
            {
                MostrarUnaMascota(listadoMascotas[i], listadoRazas[j]);
            }
        }

    }
}

int BuscarIdMascota(sMascotas listadoMascotas[], int sizeMascotas, sRaza listadoRazas[], int sizeRazas)
{
    int i;
    int idIngresado;

    MostrarListadoSoloMascotas(listadoMascotas, sizeMascotas, listadoRazas, sizeRazas);
    idIngresado = GetInt("Ingrese ID de la MASCOTA: ");

    for(i = 0; i<sizeMascotas; i++)
    {
        if(listadoMascotas[i].id == idIngresado && listadoMascotas[i].isEmpty == OCUPADO)
        {
            return i;
        }
    }
    return -1;
}

int BuscarIdRaza(sMascotas unaMascota, sRaza listadoRaza[], int sizeRaza)
{
    int i;
    int index;

    for(i = 0; i<sizeRaza; i++)
    {
        if(unaMascota.idRaza == listadoRaza[i].id)
        {
            index = i;
            break;
        }
    }
    return index;
}

int BajaMascota(sMascotas listadoMascotas[], int sizeMascotas, sRaza listadoRaza[], int sizeRazas)
{
    int indexMascota;
    int indexRaza;
    char respuesta[4];

    indexMascota = BuscarIdMascota(listadoMascotas, sizeMascotas, listadoRaza, sizeRazas);

    if(indexMascota != -1)
    {
        do
        {
            system("cls");
            indexRaza = BuscarIdRaza(listadoMascotas[indexMascota], listadoRaza, sizeRazas);

            printf("%15s %15s %18s %18s %18s %10s %10s %10s \n","ID","NOMBRE","TIPO","RAZA","PAIS","EDAD","PESO","SEXO");
            MostrarUnaMascota(listadoMascotas[indexMascota], listadoRaza[indexRaza]);

            GetString("Desea dar de baja a esta mascota (SI - NO): ",respuesta);
            strlwr(respuesta);

        }while(strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);

        if(strcmp(respuesta, "si") == 0)
        {
            listadoMascotas[indexMascota].isEmpty = LIBRE;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return indexMascota;
}

void OrdenarMascotasPorTipo(sMascotas listadoMascotas[], int sizeMascotas)
{
    sMascotas auxMascotas;

    int i;
    int j;
    for(i = 1; i<sizeMascotas-1; i++)
    {
        for(j = i+1; j<sizeMascotas; j++)
        {
            if(stricmp(listadoMascotas[i].tipo, listadoMascotas[j].tipo) > 0)
            {
                auxMascotas = listadoMascotas[i];
                listadoMascotas[i] = listadoMascotas[j];
                listadoMascotas[j] = auxMascotas;
            }
        }
    }
}

void MostrarMascotasPorTipo(sMascotas listadoMascotas[], int sizeMascotas, sRaza listadoRaza[], int sizeRaza)
{
    int i;
    int j;

    char respuesta[10];

    do
    {
        printf("Que desea mostrar. PERRO - GATO - RARO \n");
        GetString("Ingrese tipo de mascota a mostrar: ", respuesta);

    }while(strcmp(respuesta, "Perro") != 0 && strcmp(respuesta, "Gato") != 0 && strcmp(respuesta, "Raro") != 0);

    printf("%15s %15s %18s %18s %10s %10s %10s %10s \n","ID","NOMBRE","TIPO","RAZA","PAIS","EDAD","PESO","SEXO");
    for(i = 0; i<sizeMascotas; i++)
    {
        for(j = 0; j<sizeMascotas; j++)
        {
            if(listadoMascotas[i].isEmpty == OCUPADO && strcmp(listadoMascotas[i].tipo, respuesta) == 0 && listadoMascotas[i].idRaza == listadoRaza[j].id)
            {
                MostrarUnaMascota(listadoMascotas[i], listadoRaza[j]);
            }
        }
    }
}

int SumaEdadMascotas(sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;
    int acumuladorEdad = 0;

    for(i = 0; i<sizeMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO)
        {
            acumuladorEdad += listadoMascotas[i].edad;
        }
    }
    return acumuladorEdad;
}

int ContadorMascotas(sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;
    int contadorMascotas = 0;

    for(i = 0; i<sizeMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO)
        {
            contadorMascotas++;
        }
    }
    return contadorMascotas;
}

void PromedioEdadMascota(sMascotas listadoMascotas[], int sizeMascotas)
{
    int edadSumada;
    int cantidadMascota;
    float promedio;

    edadSumada = SumaEdadMascotas(listadoMascotas, sizeMascotas);
    cantidadMascota = ContadorMascotas(listadoMascotas, sizeMascotas);

    promedio = (float)edadSumada/cantidadMascota;

    printf("PROMEDIO DE EDAD ENTRE MASCOTAS: %.3f \n",promedio);
}

void PromedioEdadMascotaPorTipo(sMascotas listadoMascota[], int sizeMascotas)
{
    char respuesta[30];
    int edadMascotas;
    int cantidadMascotas;
    float promedio;

    do
    {
        printf("TIPOS: PERRO - GATO - RARO \n");
        printf("Ingrese TIPO de MASCOTA para calcular el PROMEDIO. \n");
        GetString("Ingrese TIPO: ", respuesta);

    }while(strcmp(respuesta, "Gato") != 0 && strcmp(respuesta, "Perro") != 0 && strcmp(respuesta, "Raro") != 0);

    if(strcmp(respuesta, "Gato") == 0)
    {
        edadMascotas = SumaEdadMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
        cantidadMascotas = ContadorMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
    }
    else if(strcmp(respuesta, "Perro") == 0)
    {
        edadMascotas = SumaEdadMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
        cantidadMascotas = ContadorMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
    }
    else
    {
        edadMascotas = SumaEdadMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
        cantidadMascotas = ContadorMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
    }
    promedio = (float)edadMascotas/cantidadMascotas;

    printf("Promedio de edad de mascota del TIPO %s es: %.3f \n",respuesta, promedio);
}

int SumaEdadMascotasPorTipo(sMascotas listadoMascotas[], int sizeMascotas, char tipo[])
{
    int i;
    int sumaEdad = 0;

    for(i = 0; i<sizeMascotas; i++)
    {
        if(strcmp(tipo, listadoMascotas[i].tipo) == 0 && listadoMascotas[i].isEmpty == OCUPADO)
        {
            sumaEdad += listadoMascotas[i].edad;
        }
    }
    return sumaEdad;
}

int ContadorMascotasPorTipo(sMascotas listadoMascotas[], int sizeMascotas, char tipo[])
{
    int i;
    int cantidadMascotas = 0;

    for(i = 0; i<sizeMascotas; i++)
    {
        if(strcmp(tipo, listadoMascotas[i].tipo) == 0 && listadoMascotas[i].isEmpty == OCUPADO)
        {
            cantidadMascotas++;
        }
    }
    return cantidadMascotas;
}



