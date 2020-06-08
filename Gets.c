#include "Gets.h"

int GetInt(char mensaje[])
{
    char entero[20];
    int enteroValidado;
    int validacion;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%s",entero);
        validacion = ValidarNumerosEnteros(entero);
    }while(validacion == 0);

    enteroValidado = atoi(entero);

    return enteroValidado;
}

int ValidarNumerosEnteros(char entero[])
{
    int i;

    for(i = 0; i<strlen(entero); i++)
    {
        if(!(isdigit(entero[i])))
        {
            printf("Ingresa solo numeros. \n");
            return 0;
        }
    }
    return 1;
}

float GetFloat(char mensaje[])
{
    float flotante;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&flotante);

    return flotante;
}

void GetString(char mensaje[], char cadena[])
{
    int validacion;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(cadena, 30, stdin);
        cadena[strlen(cadena)-1] = '\0';
        validacion = ValidarCadenaDeCaracteres(cadena);

    }while(validacion == 0);

    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
}

int ValidarCadenaDeCaracteres(char cadena[])
{
    int i;

    for(i = 0; i<strlen(cadena); i++)
    {
        if(!( (cadena[i] >= 65 && cadena[i] <= 90) || (cadena[i] >= 97 && cadena[i] <= 122) ))
        {
            printf("Por favor ingrese solo LETRAS y SIN ESPACIOS. \n ");
            return 0;
        }
    }
    return 1;
}
