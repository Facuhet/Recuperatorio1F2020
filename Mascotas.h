#include "Raza.h"

typedef struct
{
    int id;
    char nombre[30];
    char tipo[30];
    int edad;
    float peso;
    char sexo[10];
    int idCliente;
    int idRaza;
    int isEmpty;

}sMascotas;

void HardcodeoMascotas(sMascotas [], int);

void InicializarMascotas(sMascotas [], int);

int BuscarMascotaLibre(sMascotas [], int);

int BuscarIdMascota(sMascotas [], int , sRaza [], int);

int BuscarIdRaza(sMascotas , sRaza [], int );

int BajaMascota(sMascotas [], int, sRaza [], int);

void MostrarListadoSoloMascotas(sMascotas [], int, sRaza [], int);

void MostrarUnaMascota(sMascotas, sRaza);

void OrdenarMascotasPorTipo(sMascotas [], int);

void MostrarMascotasPorTipo(sMascotas [], int, sRaza [], int);

int ContadorMascotas(sMascotas [], int);

int SumaEdadMascotas(sMascotas [], int);

void PromedioEdadMascota(sMascotas [], int);

int SumaEdadMascotasPorTipo(sMascotas [], int, char[]);

int ContadorMascotasPorTipo(sMascotas [], int, char[]);

void PromedioEdadMascotaPorTipo(sMascotas [], int);

