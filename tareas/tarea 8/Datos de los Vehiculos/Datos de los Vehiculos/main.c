#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct
{
    char marca[MAX];
    char modelo[MAX];
    int fecha;
    float precio;
} vehiculo;

void agregarVehiculo();
void mostrarVehiculo();

void main(void)
{
int opcion;
do
{
    printf("\n============= MENU ==============\n");
    printf("1. Agregar vehiculo\n");
    printf("2. Mostrar lista de vehiculos\n");
    printf("0. Salir\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);
    getchar();

    switch(opcion)
    {
        case 1: agregarVehiculo();
            break;
        case 2: mostrarVehiculo();
            break;
        case 0: printf("\nSaliendo del programa...\n");
            break;
        default:
            printf("Opcion invalida. Intente de nuevo. \n");
    }
} while (opcion != 0);
}

void agregarVehiculo()
{
FILE *archivo = fopen("vehiculos.txt", "a");
if (!archivo)
{
    printf("No se pudo abrir el archivo.\n");
    return;
}

vehiculo v;

printf("\nIngrese la marca: ");
fgets(v.marca, MAX, stdin);
v.marca[strcspn(v.marca, "\n")] = '\0';

printf("Ingrese el modelo: ");
fgets(v.modelo, MAX, stdin);
v.modelo[strcspn(v.modelo, "\n")] = '\0';

printf("Ingrese la fecha: ");
scanf("%d", &v.fecha);

printf("Ingrese el precio: ");
scanf("%f", &v.precio);
getchar();

fprintf(archivo, "%s;%s;%d;%.2f\n", v.marca, v.modelo, v.fecha, v.precio);

fclose(archivo);

printf("\nVehiculo registrado correctamente.\n");
}

void mostrarVehiculo()
{
FILE *archivo = fopen("vehiculos.txt", "r");
if (!archivo)
{
    printf("\nNo hay vehiculos registrados aun.\n");
    return;
}

vehiculo v;

printf("\n===== Lista de Vehiculos ====\n");

while (fscanf(archivo, "%[^;];%[^;];%d;%f\n", v.marca, v.modelo, &v.fecha, &v.precio) == 4)
{
    printf("\nMarca:    %s\n", v.marca);
    printf("Modelo: %s\n", v.modelo);
    printf("Fecha:  %d\n", v.fecha);
    printf("Precio: %.2f\n", v.precio);
}

fclose(archivo);
}
