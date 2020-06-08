
typedef struct
{
    int id;
    char nombre[30];
    char apellido[30];
    char localidad[30];
    int telefono;
    int edad;
    char sexo[10];
    int isEmpty;

}sClientes;

void HardcodeoClientes(sClientes [], int);

void MostrarCliente(sClientes);

void MostrarListadoClientes(sClientes [], int);

int BuscarClienteLibre(sClientes [], int );

int BuscarIdCliente(sClientes [], int);

int AltaClientes(sClientes [], int, int);

sClientes CargarCliente(sClientes);

int ModificarCliente(sClientes [], int);

int SumaClientesSexo(sClientes [], int, char[]);

int ContadorClientesSexo(sClientes [], int);

void PromedioClientesSexo(sClientes [], int);
