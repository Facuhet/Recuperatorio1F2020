#include "Mascotas.h"
#include "Clientes.h"

typedef struct
{
    int idCliente;
    int cantidadMascota;

}sAux;

void MostrarClientesConMascotas(sClientes [], int, sMascotas [], int, sRaza [], int);

void MostrarListadoMascotas(sMascotas [], sClientes [], sRaza [], int, int, int);

void MostrarMascotaConCliente(sMascotas, sClientes, sRaza);

int BorradoClienteCascada(sClientes [], int , sMascotas [], int);

int AltaMascotas(sMascotas [], int, int, sRaza [], int, sClientes [], int);

sMascotas CargarMascotas(sMascotas, sRaza[], int, sClientes [], int);

void MostrarClientesConMasDeUnaMascota(sClientes [], sMascotas [], int, int);

void InicializarStructAux(sAux [], sClientes [], int);

void ContadorMascotas_Clientes(sAux [], sMascotas [], int, int);

void MostrarMascotasMasTres(sMascotas [], sClientes [], sRaza [], int, int, int);

void MostrarClientesConMasDeUnaMascota(sClientes [], sMascotas [], int, int);

void OrdenarClientesPorCantidad(sAux [], sClientes [], sMascotas [], int, int);

void MostrarClientesConMascotaOrdenado(sClientes [], sMascotas[], int, int, sRaza [], int);

void OrdenarClientesPorCantidadNombre(sAux [], sClientes [], sMascotas [], int, int);

void MostrarClientesPorCantidadMascotaNombre(sClientes [], sMascotas [], int, int, sRaza [], int);

int ModificarMascota(sMascotas [], int, sRaza [], int, sClientes [], int);

int BuscarClienteIndice(sClientes [], sMascotas , int );

void MostrarDueniosMascotasMismoSexo(sClientes [], int, sMascotas [], int, sRaza [], int);
