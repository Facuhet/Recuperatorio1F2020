#include "Clientes_Mascotas.h"
#include "Gets.h"
#include <stdio.h>
#include <string.h>
#define OCUPADO 1
#define LIBRE 0

void MostrarMascotaConCliente(sMascotas unaMascota, sClientes unCliente, sRaza unaRaza)
{
    printf("%15s %15d %18s %18s %18s %18s %10d %10.3f %10s \n",  unCliente.nombre,
                                                                unaMascota.id,
                                                                unaMascota.nombre,
                                                                unaMascota.tipo,
                                                                unaRaza.nombreRaza,
                                                                unaRaza.pais,
                                                                unaMascota.edad,
                                                                unaMascota.peso,
                                                                unaMascota.sexo);
}


void MostrarListadoMascotas(sMascotas listadoMascotas[], sClientes listaClientes[], sRaza listadoRazas[], int sizeMascotas, int sizeClientes, int sizeRaza)
{
    int i;
    int j;
    int k;

    for(i=0; i<sizeMascotas; i++)
    {
        for(j=0; j<sizeRaza; j++)
        {
            for(k = 0; k<sizeClientes; k++)
            {
                if(listaClientes[k].isEmpty == OCUPADO && listadoMascotas[i].isEmpty == OCUPADO &&listadoMascotas[i].idCliente == listaClientes[k].id && listadoMascotas[i].idRaza == listadoRazas[j].id)
                {
                    MostrarMascotaConCliente(listadoMascotas[i],listaClientes[k],listadoRazas[j]);
                }
            }
        }
    }
}

void MostrarClientesConMascotas(sClientes listadoClientes[], int sizeClientes, sMascotas listadoMascotas[], int sizeMascotas, sRaza listadoRaza[], int sizeRaza)
{
    int i;
    int j;
    int k;

    for(i=0; i<sizeClientes; i++)
    {
        if(listadoClientes[i].isEmpty == OCUPADO)
        {
            printf("----------------------------------------------------------------------------------------\n");
            printf("%40s %5s\n\n","Cliente: ",listadoClientes[i].nombre);
            printf("%15s %18s %18s %18s %10s %10s %10s\n\n","NOMBRE MASCOTA","TIPO","NOMBRE RAZA","PAIS RAZA","EDAD","PESO","SEXO");

        }

        for(j=0; j<sizeMascotas; j++)
        {
            for(k=0; k<sizeRaza; k++)
            {

                if(listadoClientes[i].id == listadoMascotas[j].idCliente && listadoMascotas[j].isEmpty == OCUPADO && listadoMascotas[j].idRaza == listadoRaza[k].id)
                {
                    printf("%15s %18s %18s %18s %10d %10.3f %10s \n",        listadoMascotas[j].nombre,
                                                                        listadoMascotas[j].tipo,
                                                                        listadoRaza[k].nombreRaza,
                                                                        listadoRaza[k].pais,
                                                                        listadoMascotas[j].edad,
                                                                        listadoMascotas[j].peso,
                                                                        listadoMascotas[j].sexo);
                }
            }
        }
    }
}

int AltaMascotas(sMascotas listadoMascotas[], int sizeMascotas, int idMascota, sRaza listadoRaza[], int sizeRaza, sClientes listadoClientes[], int sizeClientes)
{
    int indiceEncontrado;

    indiceEncontrado = BuscarMascotaLibre(listadoMascotas, sizeMascotas);

    if(indiceEncontrado != -1)
    {
        listadoMascotas[indiceEncontrado] = CargarMascotas(listadoMascotas[indiceEncontrado], listadoRaza, sizeRaza, listadoClientes, sizeClientes);
        listadoMascotas[indiceEncontrado].id = idMascota;
        return 1;
    }
    else
    {
        return -1;
    }
}

sMascotas CargarMascotas(sMascotas auxMascotas,sRaza listadoRaza[], int sizeRaza, sClientes listadoClientes[], int sizeClientes)
{
    GetString("Ingrese nombre de la mascota: ",auxMascotas.nombre);

    do
    {
        printf("TIPOS : GATO - PERRO - RARO \n");
        GetString("Ingrese tipo de la mascota: ",auxMascotas.tipo);

    }while(strcmp(auxMascotas.tipo, "Gato") != 0 && strcmp(auxMascotas.tipo, "Perro") != 0 && strcmp(auxMascotas.tipo, "Raro") != 0 );

    MostrarRazas(listadoRaza, sizeRaza);
    auxMascotas.idRaza = GetInt("Ingrese ID RAZA de la mascota: ");

    auxMascotas.edad = GetInt("Ingrese edad de la mascota: ");

    auxMascotas.peso = GetFloat("Ingrese peso de la mascota: ");

    do
    {
        printf("SEXO: MACHO - HEMBRA \n");
        GetString("Ingrese sexo de la mascota: ",auxMascotas.sexo);

    }while(strcmp(auxMascotas.sexo, "Hembra") != 0 && strcmp(auxMascotas.sexo, "Macho") != 0);

    printf("\n\n%15s %15s %18s %18s %10s %10s %10s \n\n","ID","NOMBRE","APELLIDO","LOCALIDAD","EDAD","TELEFONO","SEXO");
    MostrarListadoClientes(listadoClientes, sizeClientes);
    auxMascotas.idCliente = GetInt("\nIngrese ID del cliente para asignarle una mascota: ");

    auxMascotas.isEmpty = OCUPADO;

    return auxMascotas;
}

int BorradoClienteCascada(sClientes listadoCliente[], int sizeClientes, sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;
    int indice;
    char respuesta[4];

    indice = BuscarIdCliente(listadoCliente, sizeClientes);

    if(indice != -1)
    {
        do
        {
            printf("%15s %15s %18s %18s %10s %10s %10s \n\n","ID","NOMBRE","APELLIDO","LOCALIDAD","EDAD","TELEFONO","SEXO");
            MostrarCliente(listadoCliente[indice]);
            printf("Esta seguro de dar de baja a este cliente, se borrara tambien las mascotas. \n\n");
            printf("SI - NO \n");
            GetString("Ingrese opcion: ",respuesta);

        }while(strcmp(respuesta, "Si") != 0 && strcmp(respuesta, "No") != 0);

        if(strcmp(respuesta, "Si") == 0)
        {
            for(i = 0; i<sizeMascotas; i++)
            {
                if(listadoCliente[indice].id == listadoMascotas[i].idCliente)
                {
                    listadoMascotas[i].isEmpty = LIBRE;
                }
            }
            listadoCliente[indice].isEmpty = LIBRE;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return -1;
}


void MostrarClientesConMasDeUnaMascota(sClientes listadoClientes[], sMascotas listadoMascotas[], int sizeClientes, int sizeMascotas)
{
    int i;
    int j;

    sAux Clientes_Mascotas[sizeClientes];
    InicializarStructAux(Clientes_Mascotas, listadoClientes, sizeClientes);
    ContadorMascotas_Clientes(Clientes_Mascotas, listadoMascotas, sizeMascotas, sizeClientes);

    printf("%15s %15s %15s \n","ID CLIENTE","NOMBRE CLIENTE","CANT. MASCOTA");

    for(i = 0; i<sizeClientes; i++)
    {
        for(j = 0; j<sizeClientes; j++)
        {
            if(listadoClientes[j].isEmpty == OCUPADO && listadoClientes[j].id == Clientes_Mascotas[i].idCliente && Clientes_Mascotas[i].cantidadMascota > 1)
            {
                printf("%15d %15s %15d  \n",listadoClientes[i].id, listadoClientes[i].nombre, Clientes_Mascotas[j].cantidadMascota);
            }
        }
    }
}

void InicializarStructAux(sAux listadoAux[],sClientes listadoClientes[], int sizeClientes)
{
    int i;

    for(i = 0; i<sizeClientes; i++)
    {
        listadoAux[i].idCliente = listadoClientes[i].id;
        listadoAux[i].cantidadMascota = 0;
    }
}

void ContadorMascotas_Clientes(sAux Clientes_Mascota[], sMascotas listadoMascotas[], int sizeMascotas, int sizeClientes)
{
    int i;
    int j;

    for(i = 0; i<sizeClientes; i++)
    {
        for(j = 0; j<sizeMascotas; j++)
        {
            if(listadoMascotas[j].isEmpty == OCUPADO && listadoMascotas[j].idCliente == Clientes_Mascota[i].idCliente)
            {
                Clientes_Mascota[i].cantidadMascota++;
            }
        }
    }
}

void MostrarMascotasMasTres(sMascotas listadoMascotas[], sClientes listaClientes[], sRaza listadoRazas[], int sizeMascotas, int sizeClientes, int sizeRazas)
{
    int i;
    int j;
    int k;

    for(i=0; i<sizeMascotas; i++)
    {
        for(j=0; j<sizeClientes; j++)
        {
            for(k = 0; k<sizeRazas; k++)
            {
                if(listaClientes[j].isEmpty == OCUPADO && listadoMascotas[i].isEmpty == OCUPADO &&listadoMascotas[i].idCliente == listaClientes[j].id && listadoMascotas[i].edad > 3 && listadoMascotas[i].idRaza == listadoRazas[k].id)
                {
                    MostrarMascotaConCliente(listadoMascotas[i],listaClientes[j], listadoRazas[k]);
                }
            }
        }
    }
}

void OrdenarClientesPorCantidad(sAux Clientes_Mascotas[], sClientes listadoClientes[], sMascotas listadoMascotas[], int sizeClientes, int sizeMascotas)
{
    int i;
    int j;
    sAux contadorAuxiliar;

    InicializarStructAux(Clientes_Mascotas, listadoClientes, sizeClientes);
    ContadorMascotas_Clientes(Clientes_Mascotas, listadoMascotas, sizeMascotas, sizeClientes);

    for(i = 0; i<sizeClientes-1; i++)
    {
        for(j = i+1; j<sizeClientes; j++)
        {
            if(Clientes_Mascotas[i].cantidadMascota < Clientes_Mascotas[j].cantidadMascota)
            {
                contadorAuxiliar = Clientes_Mascotas[i];
                Clientes_Mascotas[i] = Clientes_Mascotas[j];
                Clientes_Mascotas[j] = contadorAuxiliar;
            }
        }
    }
}

void MostrarClientesConMascotaOrdenado(sClientes listadoClientes[], sMascotas listadoMascotas[], int sizeClientes, int sizeMascotas, sRaza listadoRazas[], int sizeRazas)
{
    int i;
    int j;
    int k;
    int m;

    sAux Clientes_Mascotas[sizeClientes];

    OrdenarClientesPorCantidad(Clientes_Mascotas, listadoClientes, listadoMascotas, sizeClientes, sizeMascotas);

    for(i = 0; i<sizeClientes; i++)
    {
        for(j = 0; j<sizeClientes; j++)
        {
            if(Clientes_Mascotas[i].idCliente == listadoClientes[j].id && listadoClientes[j].isEmpty == OCUPADO)
            {
                printf("---------------------------------------------------------------------------------------------------------------------------\n");

                printf("%42s CLIENTE <<<<<<< \n",">>>>>>>");
                printf("%15s %15s %18s %18s %10s %10s %10s \n\n","ID","NOMBRE","APELLIDO","LOCALIDAD","EDAD","TELEFONO","SEXO");

                MostrarCliente(listadoClientes[j]);

                printf("\n%42s MASCOTA <<<<<<< \n",">>>>>>>");
                printf("%15s %15s %18s %18s %18s %10s %10s %10s \n\n","ID","NOMBRE","TIPO","NOMBRE RAZA","PAIS RAZA","EDAD","PESO","SEXO");

                for(k = 0; k<sizeMascotas; k++)
                {
                    for(m = 0; m<sizeRazas; m++)
                    {
                        if(listadoClientes[j].id == listadoMascotas[k].idCliente && listadoMascotas[k].isEmpty == OCUPADO && listadoMascotas[k].idRaza == listadoRazas[m].id)
                        {
                            MostrarUnaMascota(listadoMascotas[k], listadoRazas[m]);
                            //printf("%15d %15s %15d \n",listadoClientes[j].id, listadoClientes[j].nombre, Clientes_Mascotas[i].cantidadMascota);
                        }
                    }
                }
            }
        }
    }
}

void OrdenarClientesPorCantidadNombre(sAux Clientes_Mascotas[], sClientes listadoClientes[], sMascotas listadoMascotas[], int sizeClientes, int sizeMascotas)
{
    int i;
    int j;
    sAux contadorAuxiliar;

    InicializarStructAux(Clientes_Mascotas, listadoClientes, sizeClientes);
    ContadorMascotas_Clientes(Clientes_Mascotas, listadoMascotas, sizeMascotas, sizeClientes);

    for(i = 0; i<sizeClientes-1; i++)
    {
        for(j = i+1; j<sizeClientes; j++)
        {
            if(Clientes_Mascotas[i].cantidadMascota < Clientes_Mascotas[j].cantidadMascota || Clientes_Mascotas[i].cantidadMascota == Clientes_Mascotas[j].cantidadMascota)
            {

                contadorAuxiliar = Clientes_Mascotas[i];
                Clientes_Mascotas[i] = Clientes_Mascotas[j];
                Clientes_Mascotas[j] = contadorAuxiliar;
            }
            else
            {
                if(strcmp(listadoClientes[i].nombre, listadoMascotas[j].nombre) > 0 && strcmp(listadoClientes[i].nombre, listadoClientes[j].nombre) == 0)
                {
                    contadorAuxiliar = Clientes_Mascotas[i];
                    Clientes_Mascotas[i] = Clientes_Mascotas[j];
                    Clientes_Mascotas[j] = contadorAuxiliar;
                }
            }
        }
    }
}

void MostrarClientesPorCantidadMascotaNombre(sClientes listadoClientes[], sMascotas listadoMascotas[], int sizeClientes, int sizeMascotas, sRaza listadoRazas[], int sizeRazas)
{
    int i;
    int j;
    int k;
    int m;

    sAux Clientes_Mascotas[sizeClientes];

    OrdenarClientesPorCantidadNombre(Clientes_Mascotas, listadoClientes, listadoMascotas, sizeClientes, sizeMascotas);

    for(i = 0; i<sizeClientes; i++)
    {
        for(j = 0; j<sizeClientes; j++)
        {
            if(Clientes_Mascotas[i].idCliente == listadoClientes[j].id && listadoClientes[j].isEmpty == OCUPADO)
            {
                printf("--------------------------------------------------------------------------------------------------------------------------\n");

                printf("%48s CLIENTE <<<<<<< \n",">>>>>>>");
                printf("%15s %15s %18s %18s %10s %10s %10s \n\n","ID","NOMBRE","APELLIDO","LOCALIDAD","EDAD","TELEFONO","SEXO");

                MostrarCliente(listadoClientes[j]);

                printf("\n%48s MASCOTA <<<<<<< \n",">>>>>>>");
                printf("%15s %15s %18s %18s %18s %10s %10s %10s \n\n","ID","NOMBRE","TIPO","NOMBRE RAZA","PAIS RAZA","EDAD","PESO","SEXO");

                for(k = 0; k<sizeMascotas; k++)
                {
                    for(m = 0; m<sizeRazas; m++)
                    {
                        if(listadoClientes[j].id == listadoMascotas[k].idCliente && listadoMascotas[k].isEmpty == OCUPADO && listadoMascotas[k].idRaza == listadoRazas[m].id)
                        {
                            MostrarUnaMascota(listadoMascotas[k], listadoRazas[m]);
                            //printf("%15d %15s %15d \n",listadoClientes[j].id, listadoClientes[j].nombre, Clientes_Mascotas[i].cantidadMascota);
                        }
                    }
                }
            }
        }
    }
}

int ModificarMascota(sMascotas listadoMascotas[], int sizeMascotas, sRaza listadoRazas[], int sizeRazas, sClientes listadoClientes[], int sizeClientes)
{
    int indexMascota;
    int indexRaza;
    int indexCliente;
    int opcion;

    indexMascota = BuscarIdMascota(listadoMascotas, sizeMascotas, listadoRazas, sizeRazas);

    if(indexMascota != -1)
    {
        do
        {
            system("cls");
            indexCliente = BuscarClienteIndice(listadoClientes, listadoMascotas[indexMascota], sizeClientes);
            printf("%15s %15s %18s %18s %18s %18s %10s %10s %10s\n\n","NOMBRE CLIENTE","ID MASCOTA","NOMBRE MASCOTA","TIPO","NOMBRE RAZA","PAIS RAZA","EDAD","PESO","SEXO");
            indexRaza = BuscarIdRaza(listadoMascotas[indexMascota], listadoRazas, sizeRazas);
            MostrarMascotaConCliente(listadoMascotas[indexMascota], listadoClientes[indexCliente], listadoRazas[indexRaza]);
            printf("\nQue desea modifcar?  \n\n");
            printf("1-NOMBRE. \n");
            printf("2-TIPO. \n");
            printf("3-RAZA. \n");
            printf("4-EDAD. \n");
            printf("5-PESO. \n");
            printf("6-SEXO. \n");
            printf("7-MODIFICAR EL DUENIO \n");
            printf("8-SALIR. \n");
            opcion = GetInt("Ingrese opcion: ");

            switch(opcion)
            {
                case 1:
                    GetString("Ingrese nuevo NOMBRE: ", listadoMascotas[indexMascota].nombre);
                break;

                case 2:
                    do
                    {
                        printf("TIPO: PERRO - GATO - RARO \n");
                        GetString("Ingrese nuevo TIPO: ", listadoMascotas[indexMascota].tipo);

                    }while(strcmp(listadoMascotas[indexMascota].tipo, "Perro") != 0 && strcmp(listadoMascotas[indexMascota].tipo, "Gato") != 0 && strcmp(listadoMascotas[indexMascota].tipo, "Raro") != 0);

                break;

                case 3:
                    MostrarRazas(listadoRazas, sizeRazas);
                    listadoMascotas[indexMascota].idRaza = GetInt("\nIngrese ID de la nueva RAZA: ");
                break;

                case 4:
                    listadoMascotas[indexMascota].edad = GetInt("Ingrese nueva EDAD: ");
                break;

                case 5:
                    listadoMascotas[indexMascota].peso = GetFloat("Ingrese nuevo PESO: ");
                break;

                case 6:
                    do
                    {
                        printf("SEXO: MACHO - HEMBRA \n");
                        GetString("Ingrese nuevo SEXO: ", listadoMascotas[indexMascota].sexo);

                    }while(strcmp(listadoMascotas[indexMascota].sexo, "Macho") != 0 && strcmp(listadoMascotas[indexMascota].sexo, "Hembra") != 0);

                break;

                case 7:
                    MostrarListadoClientes(listadoClientes, sizeClientes);
                    listadoMascotas[indexMascota].idCliente = GetInt("\nIngrese el ID del CLIENTE. \n");
                break;

                case 8:
                break;
            }
        system("cls");
        }while(opcion != 8);

    }

    return indexMascota;
}

int BuscarClienteIndice(sClientes listadoClientes[], sMascotas unaMascota, int sizeClientes)
{
    int i;
    int index;

    for(i = 0; i<sizeClientes; i++)
    {
        if(unaMascota.idCliente == listadoClientes[i].id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void MostrarDueniosMascotasMismoSexo(sClientes listadoClientes[], int sizeClientes, sMascotas listadoMascotas[], int sizeMascotas, sRaza listadoRazas[], int sizeRazas)
{
    int indexRaza;
    int opcion;
    char auxSexoCliente[10];
    char auxSexoMascota[10];

    do
    {
        printf("Mostrar por sexo CLIENTE-MASCOTA: \n");
        printf("1.-Masculino. \n");
        printf("2.-Femeninos. \n");
        printf("3.-Salir. \n");
        scanf("%d",&opcion);

    }while(opcion > 3 || opcion < 1);

    switch(opcion)
    {
        case 1:
            strcpy(auxSexoCliente, "Masculino");
            strcpy(auxSexoMascota, "Macho");
        break;

        case 2:
            strcpy(auxSexoCliente, "Femenino");
            strcpy(auxSexoMascota, "Hembra");
        break;

        case 3:
        break;
    }

    int i;
    int j;
    for(i = 0; i<sizeClientes; i++)
    {
        if(listadoClientes[i].isEmpty == OCUPADO && strcmp(listadoClientes[i].sexo, auxSexoCliente) == 0)
        {
            printf("\n %60s <<<<<<<<<< \n",">>>>>>>>>>CLIENTE");
            printf("%15s %15s %18s %18s %10s %10s %10s \n", "ID","NOMBRE","APELLIDO","LOCALIDAD","EDAD","TELEFONO","SEXO");

            MostrarCliente(listadoClientes[i]);
            printf("\n %60s<<<<<<<<<< \n",">>>>>>>>>>MASCOTA");
            printf("%15s %15s %18s %18s %18s %10s %10s %10s \n","ID","NOMBRE","TIPO","NOMBRE RAZA","PAIS RAZA","EDAD","PESO","SEXO");

            for(j = 0; j<sizeMascotas; j++)
            {
                if(listadoClientes[i].isEmpty == OCUPADO && listadoMascotas[j].isEmpty == OCUPADO && listadoClientes[i].id == listadoMascotas[j].idCliente)
                {

                    if(strcmp(listadoClientes[i].sexo, auxSexoCliente) == 0 && strcmp(listadoMascotas[j].sexo, auxSexoMascota) == 0)
                    {

                        indexRaza = BuscarIdRaza(listadoMascotas[j], listadoRazas,sizeRazas);

                        MostrarUnaMascota(listadoMascotas[j],listadoRazas[indexRaza]);
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
}
