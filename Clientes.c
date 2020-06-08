#include "Clientes.h"
#include "Gets.h"
#include <stdio.h>
#include <string.h>
#define OCUPADO 1
#define LIBRE 0

int BuscarClienteLibre(sClientes listadoCliente[], int sizeClientes)
{
    int index;

    int i;
    for(i = 0; i<sizeClientes; i++)
    {
        index = -1;
        if(listadoCliente[i].isEmpty == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

void HardcodeoClientes(sClientes listadoClientes[], int sizeClientes)
{
    int i;
    int id[10] = {100,101,102,103,104};
    char nombre[10][30] = {"Maria","Juan","Mauricio","Ana","Jose"};
    char apellido[10][30] = {"ApellidoMaria","ApellidoJuan","ApellidoMauricio","ApellidoAna","ApellidoJose"};
    char localidad[10][30] = {"Almagro","Lanus","Avellanedad","Lomas","Olavarria"};
    int telefono[10] = {100,200,300,400,500};
    int edad[10] = {35,28,55,18,75};
    char sexo[10][10] = {"Femenino","Masculino","Masculino","Femenino","Masculino"};
    int isEmpty[10] = {OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

    for(i = 0; i<sizeClientes; i++)
    {
        listadoClientes[i].id = id[i];
        strcpy(listadoClientes[i].nombre, nombre[i]);
        strcpy(listadoClientes[i].apellido, apellido[i]);
        strcpy(listadoClientes[i].localidad, localidad[i]);
        listadoClientes[i].telefono = telefono[i];
        listadoClientes[i].edad = edad[i];
        strcpy(listadoClientes[i].sexo, sexo[i]);
        listadoClientes[i].isEmpty = isEmpty[i];
    }
}

void MostrarCliente(sClientes unCliente)
{
    printf("%15d %15s %18s %18s %10d %10d %10s \n",  unCliente.id,
                                                    unCliente.nombre,
                                                    unCliente.apellido,
                                                    unCliente.localidad,
                                                    unCliente.edad,
                                                    unCliente.telefono,
                                                    unCliente.sexo);
}

void MostrarListadoClientes(sClientes listadoClientes[], int sizeClientes)
{
    int i;

    for(i=0; i<sizeClientes; i++)
    {
        if(listadoClientes[i].isEmpty == OCUPADO)
        {
            MostrarCliente(listadoClientes[i]);
        }
    }
}

int AltaClientes(sClientes listadoClientes[], int sizeClientes, int idCliente)
{
    int index;

    index = BuscarClienteLibre(listadoClientes, sizeClientes);

    if(index != -1)
    {
        listadoClientes[index] = CargarCliente(listadoClientes[index]);
        listadoClientes[index].id = idCliente;
        return 1;
    }
    else
    {
        return -1;
    }
}

sClientes CargarCliente(sClientes auxCliente)
{
    GetString("Ingrese NOMBRE: " ,auxCliente.nombre);

    GetString("Ingrese APELLIDO: " ,auxCliente.apellido);

    GetString("Ingrese LOCALIDAD: " ,auxCliente.localidad);

    auxCliente.edad = GetInt("Ingrese EDAD: ");

    auxCliente.telefono = GetInt("Ingrese TELEFONO: ");

    do
    {
        printf("SEXO: MASCULINO - FEMENINO - OTRO \n");
        GetString("Ingrese SEXO: " ,auxCliente.sexo);
    }while(strcmp(auxCliente.sexo, "Femenino") != 0 && strcmp(auxCliente.sexo, "Masculino") != 0 && strcmp(auxCliente.sexo, "Otro") != 0);

    auxCliente.isEmpty = OCUPADO;

    return auxCliente;
}

int BuscarIdCliente(sClientes listadoClientes[], int sizeClientes)
{
    int i;
    int idIngresado;

    printf("%15s %15s %18s %18s %10s %10s %10s \n","ID","NOMBRE","APELLIDO","LOCALIDAD","EDAD","TELEFONO","SEXO");
    MostrarListadoClientes(listadoClientes, sizeClientes);
    idIngresado = GetInt("Ingrese ID del CLIENTE: ");

    for(i = 0; i<sizeClientes; i++)
    {
        if(listadoClientes[i].id == idIngresado && listadoClientes[i].isEmpty == OCUPADO)
        {
            return i;
        }
    }
    return -1;
}

int ModificarCliente(sClientes listadoClientes[], int sizeClientes)
{
    int index;
    int opcion;

    index = BuscarIdCliente(listadoClientes, sizeClientes);

    if(index != -1)
    {
        do
        {
            printf("%15s %15s %18s %18s %10s %10s %10s \n","ID","NOMBRE","APELLIDO","LOCALIDAD","EDAD","TELEFONO","SEXO");
            MostrarCliente(listadoClientes[index]);
            printf("Que desea modifcar: \n");
            printf("1-NOMBRE. \n");
            printf("2-APELLIDO. \n");
            printf("3-LOCALIDAD. \n");
            printf("4-EDAD. \n");
            printf("5-TELEONO. \n");
            printf("6-SEXO. \n");
            printf("7-SALIR. \n");
            opcion = GetInt("Ingrese opcion: ");

            switch(opcion)
            {
                case 1:
                    GetString("Ingrese nuevo NOMBRE: ", listadoClientes[index].nombre);
                break;

                case 2:
                    GetString("Ingrese nuevo APELLIDO: ", listadoClientes[index].apellido);
                break;

                case 3:
                    GetString("Ingrese nueva LOCALIDAD: ", listadoClientes[index].localidad);
                break;

                case 4:
                    listadoClientes[index].edad = GetInt("Ingrese nueva EDAD: ");
                break;

                case 5:
                    listadoClientes[index].telefono = GetInt("Ingrese nuevo TELEFONO: ");
                break;

                case 6:
                    do
                    {
                        printf("SEXO: MASCULINO - FEMENINO - OTRO\n");
                        GetString("Ingrese nuevo SEXO: ", listadoClientes[index].sexo);

                    }while(strcmp(listadoClientes[index].sexo, "Masculino") != 0 && strcmp(listadoClientes[index].sexo, "Femenino") != 0 && strcmp(listadoClientes[index].sexo, "Otro") != 0);

                break;

                case 7:
                break;
            }
        system("cls");
        }while(opcion != 7);
    }

    return index;
}

int SumaClientesSexo(sClientes listadoClientes[], int sizeClientes, char genero[])
{
    int i;
    int contadorGenero = 0;

    for(i = 0; i<sizeClientes; i++)
    {
        if(strcmp(listadoClientes[i].sexo, genero) == 0)
        {
            contadorGenero++;
        }
    }
    return contadorGenero;
}

int ContadorClientesSexo(sClientes listadoClientes[], int sizeClientes)
{
    int i;
    int cantidadClientes = 0;

    for(i = 0; i<sizeClientes; i++)
    {
        if(listadoClientes[i].isEmpty == OCUPADO)
        {
            cantidadClientes++;
        }
    }
    return cantidadClientes;

}

void PromedioClientesSexo(sClientes listadoClientes[], int sizeClientes)
{

    int sumaPorGeneroFemenino;
    int cantidadPorGenero;
    int porcentajeFemenino;
    sumaPorGeneroFemenino = SumaClientesSexo(listadoClientes, sizeClientes, "Femenino");
    cantidadPorGenero = ContadorClientesSexo(listadoClientes, sizeClientes);

    porcentajeFemenino = (sumaPorGeneroFemenino*100)/cantidadPorGenero;

    printf("PORCENTAJE MUJERES: %d %s \n",porcentajeFemenino,"%");

}
