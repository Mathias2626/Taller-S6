#include <stdio.h>
#include "inventario.h"

int ingresarProductos(char nombres[][LONG_NOMBRE], float precios[], int cantidad)
{
    int nuevaCantidad;

    printf("ingrese la cantidad de productos (max %d): ", MAX_PRODUCTOS);
    scanf("%d", &nuevaCantidad);

    if (nuevaCantidad > MAX_PRODUCTOS)
    {
        printf("no puede exceder %d productos.\n", MAX_PRODUCTOS);
        nuevaCantidad = MAX_PRODUCTOS;
    }

    for (int i = 0; i < nuevaCantidad; i++)
    {
        printf("\nProducto %d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", nombres[i]);
        printf("Precio: ");
        scanf("%f", &precios[i]);
    }

    return nuevaCantidad; // retorna la cantidad
}

float calcularPrecioTotal(float precios[], int cantidad)
{
    float total = 0;
    for (int i = 0; i < cantidad; i++)
    {
        total += precios[i];
    }
    return total;
}

void encontrarExtremos(char nombres[][LONG_NOMBRE], float precios[], int cantidad, char masCaro[], char masBarato[])
{
    if (cantidad == 0)
        return;

    float maxPrecio = precios[0];
    float minPrecio = precios[0];

    int j = 0;
    while (nombres[0][j] != '\0')
    {
        masCaro[j] = nombres[0][j];
        masBarato[j] = nombres[0][j];
        j++;
    }
    masCaro[j] = '\0';
    masBarato[j] = '\0';

    for (int i = 1; i < cantidad; i++)
    {
        if (precios[i] > maxPrecio)
        {
            maxPrecio = precios[i];
            j = 0;
            while (nombres[i][j] != '\0')
            {
                masCaro[j] = nombres[i][j];
                j++;
            }
            masCaro[j] = '\0';
        }
        if (precios[i] < minPrecio)
        {
            minPrecio = precios[i];
            j = 0;
            while (nombres[i][j] != '\0')
            {
                masBarato[j] = nombres[i][j];
                j++;
            }
            masBarato[j] = '\0';
        }
    }
}

float calcularPromedio(float precios[], int cantidad)
{
    if (cantidad == 0)
        return 0;
    float total = calcularPrecioTotal(precios, cantidad);
    return total / cantidad;
}

int buscarProducto(char nombres[][LONG_NOMBRE], float precios[], int cantidad, char nombreBuscado[])
{
    for (int i = 0; i < cantidad; i++)
    {
        int iguales = 1;
        int j = 0;

        while (nombres[i][j] != '\0' && nombreBuscado[j] != '\0')
        {
            if (nombres[i][j] != nombreBuscado[j])
            {
                iguales = 0;
                break;
            }
            j++;
        }

        if (iguales && nombres[i][j] == '\0' && nombreBuscado[j] == '\0')
        {
            return i;
        }
    }
    return -1;
}
