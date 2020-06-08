#include <stdio.h>
#include <stdlib.h>
#include "Clientes_Mascotas.h"
#include "Gets.h"
#define QTY_CLIENTES 10
#define QTY_MASCOTAS 20
#define QTY_RAZA 11

int main()
{
    sClientes listadoClientes[QTY_CLIENTES];
    sMascotas listadoMascotas[QTY_MASCOTAS];
    sRaza listadoRaza[QTY_RAZA];

    InicializarMascotas(listadoMascotas, QTY_MASCOTAS);

    HardcodeoClientes(listadoClientes, QTY_CLIENTES);
    HardcodeoMascotas(listadoMascotas, QTY_MASCOTAS);
    HardCodeoRaza(listadoRaza, QTY_RAZA);

    int opcion;
    int funcionRetorno;
    int idClientes = 1000;
    int idMascotas = 5000;

    do
    {
        printf("1-Mostrar CLIENTES.\n");
        printf("2-Mostrar MASCOTAS.\n");
        printf("3-Mostrar CLIENTES-MASCOTAS.\n");
        printf("4-Alta MASCOTAS.\n");
        printf("5-Baja MASCOTA.\n");
        printf("6-Modificar MASCOTA.\n");
        printf("7-Alta CLIENTE. \n");
        printf("8-Borrado CLIENTE en CASCADA. \n");
        printf("9-Ordenar MASCOTA por TIPO y MOSTRAR. \n");
        printf("10-Modificar CLIENTE.\n");
        printf("11-Mostrar CLIENTES con mas de una MASCOTA.\n");
        printf("12-Mostrar MASCOTAS de mas de 3 anios con su DUENIO.\n");
        printf("13-Mostrar MASCOTAS por TIPO. \n");
        printf("14-Ordenar CLIENTES por cantidad de MASCOTAS y MOSTRAR. \n");
        printf("15-Ordenar CLIENTES por CANTIDAD de MASCOTAS y ORDEN ALFABETICO y MOSTRAR. \n");
        printf("16-Promedio de EDAD de las MASCOTAS. \n");
        printf("17-Promedio de EDAD de las MASCOTAS por TIPO. \n");
        printf("18-Porcentaje de MUJERES sobre TOTAL DE CLIENTES. \n");
        printf("19-Listar DUENIOS que tienen mascotas del mismo SEXO. \n");
        printf("20-SALIR. \n");


        opcion = GetInt("Ingrese opcion: ");

        system("cls");

        switch(opcion)
        {
            case 1:
                printf("%15s %15s %18s %18s %10s %10s %10s \n\n","ID","NOMBRE","APELLIDO","LOCALIDAD","EDAD","TELEFONO","SEXO");
                MostrarListadoClientes(listadoClientes, QTY_CLIENTES);
            break;

            case 2:
                printf("%15s %15s %18s %18s %18s %18s %10s %10s %10s\n\n","NOMBRE CLIENTE","ID MASCOTA","NOMBRE MASCOTA","TIPO","NOMBRE RAZA","PAIS RAZA","EDAD","PESO","SEXO");
                MostrarListadoMascotas(listadoMascotas,listadoClientes, listadoRaza, QTY_MASCOTAS, QTY_CLIENTES, QTY_RAZA);
            break;

            case 3:
                printf("\n %40s \n","CLIENTES CON SUS MASCOTAS");
                MostrarClientesConMascotas(listadoClientes, QTY_CLIENTES, listadoMascotas, QTY_MASCOTAS, listadoRaza, QTY_RAZA);
                printf("----------------------------------------------------------------------------------------\n");
            break;

            case 4:

                if(AltaMascotas(listadoMascotas, QTY_MASCOTAS, idMascotas, listadoRaza, QTY_RAZA, listadoClientes, QTY_CLIENTES) != -1)
                {
                    idMascotas++;
                }
                else
                {
                    printf("NO HAY ESPACIO PARA CARGAR MAS. \n");
                }
            break;

            case 5:
                funcionRetorno = BajaMascota(listadoMascotas, QTY_MASCOTAS, listadoRaza, QTY_RAZA);
                if(funcionRetorno == -1)
                {
                    printf("ID Mascota no encontrada. \n");
                }
                else if(funcionRetorno == 0)
                {
                    printf("Baja de mascota cancelada. \n");
                }
                else
                {
                    printf("Mascota dada de baja con exito. \n");
                }

            break;

            case 6:
                funcionRetorno = ModificarMascota(listadoMascotas, QTY_MASCOTAS, listadoRaza, QTY_RAZA, listadoClientes, QTY_CLIENTES);
                if(funcionRetorno == -1)
                {
                    printf("ID Mascota no encontrada. \n");
                }
            break;

            case 7:
                if(AltaClientes(listadoClientes, QTY_CLIENTES, idClientes) != -1)
                {
                    idClientes++;
                }
                else
                {
                    printf("NO HAY ESPACIO PARA CARGAR CLIENTES. \n");
                }
            break;

            case 8:
                funcionRetorno = BorradoClienteCascada(listadoClientes, QTY_CLIENTES, listadoMascotas, QTY_MASCOTAS);
                switch(funcionRetorno)
                {
                    case 1:
                        printf("Cliente dado de baja con sus mascotas exitosamente... \n");
                    break;

                    case 0:
                        printf("Borrado de cliente CANCELADO. \n");
                    break;

                    case -1:
                        printf("NO SE ENCONTRO AL CLIENTE. \n");
                    break;
                }

            break;

            case 9:
                printf("%15s %15s %15s %18s %18s %10s %10s %10s %10s\n\n","NOMBRE CLIENTE","ID MASCOTA","NOMBRE","TIPO","RAZA","PAIS","EDAD","PESO","SEXO");
                OrdenarMascotasPorTipo(listadoMascotas, QTY_MASCOTAS);
                MostrarListadoMascotas(listadoMascotas, listadoClientes, listadoRaza, QTY_MASCOTAS, QTY_CLIENTES, QTY_RAZA);
            break;

            case 10:
                funcionRetorno = ModificarCliente(listadoClientes, QTY_CLIENTES);
            break;

            case 11:
                MostrarClientesConMasDeUnaMascota(listadoClientes, listadoMascotas, QTY_CLIENTES, QTY_MASCOTAS);
            break;

            case 12:
                printf("%15s %15s %18s %18s %18s %18s %10s %10s %10s \n","NOMBRE CLIENTE","ID","NOMBRE","TIPO","RAZA","PAIS","EDAD","PESO","SEXO");
                MostrarMascotasMasTres(listadoMascotas, listadoClientes, listadoRaza, QTY_MASCOTAS, QTY_CLIENTES, QTY_RAZA);
            break;

            case 13:
                MostrarMascotasPorTipo(listadoMascotas, QTY_MASCOTAS, listadoRaza, QTY_RAZA);
            break;

            case 14:
                MostrarClientesConMascotaOrdenado(listadoClientes, listadoMascotas, QTY_CLIENTES, QTY_MASCOTAS, listadoRaza, QTY_RAZA);
            break;

            case 15:
                MostrarClientesPorCantidadMascotaNombre(listadoClientes, listadoMascotas, QTY_CLIENTES, QTY_MASCOTAS, listadoRaza, QTY_RAZA);
            break;

            case 16:
                PromedioEdadMascota(listadoMascotas, QTY_MASCOTAS);
            break;

            case 17:
                PromedioEdadMascotaPorTipo(listadoMascotas, QTY_MASCOTAS);
            break;

            case 18:
                PromedioClientesSexo(listadoClientes, QTY_CLIENTES);
            break;

            case 19:
                MostrarDueniosMascotasMismoSexo(listadoClientes, QTY_CLIENTES, listadoMascotas, QTY_MASCOTAS, listadoRaza, QTY_RAZA);
            break;

            case 20:
            break;
        }
        system("pause");
        system("cls");
    }while(opcion != 20);

    return 0;
}
