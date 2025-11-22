#include <stdio.h>
#include "inventario.h"

int main()
{
    char nombres[MAX_PRODUCTOS][LONG_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int cantidad = 0;
    int opcion;
    char nombreBuscado[LONG_NOMBRE];
    char masCaro[LONG_NOMBRE], masBarato[LONG_NOMBRE];

    printf("sistema de inventario\n");

    do
    {
        printf("\nMENU\n");
        printf("1. ingresar productos\n");
        printf("2. calcular precio total\n");
        printf("3. producto más caro y más barato\n");
        printf("4. precio promedio\n");
        printf("5. buscar producto\n");
        printf("6. salir\n");
        printf("seleccione una opción: ");

        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            cantidad = ingresarProductos(nombres, precios, cantidad);
            break;

        case 2:
            if (cantidad > 0)
                printf("total: $%.2f\n", calcularPrecioTotal(precios, cantidad));
            else
                printf("no hay productos.\n");
            break;

        case 3:
            if (cantidad > 0)
            {
                encontrarExtremos(nombres, precios, cantidad, masCaro, masBarato);
                int idxC = buscarProducto(nombres, precios, cantidad, masCaro);
                int idxB = buscarProducto(nombres, precios, cantidad, masBarato);

                printf("mas caro: %s - $%.2f\n", masCaro, precios[idxC]);
                printf("mas barato: %s - $%.2f\n", masBarato, precios[idxB]);
            }
            else
                printf("no hay productos.\n");
            break;

        case 4:
            if (cantidad > 0)
                printf("promedio: $%.2f\n", calcularPromedio(precios, cantidad));
            else
                printf("no hay productos.\n");
            break;

        case 5:
            if (cantidad > 0)
            {
                printf("nombre a buscar: ");
                scanf("%s", nombreBuscado);

                int pos = buscarProducto(nombres, precios, cantidad, nombreBuscado);

                if (pos != -1)
                    printf("encontrado: %s - $%.2f\n", nombres[pos], precios[pos]);
                else
                    printf("no encontrado.\n");
            }
            else
                printf("no hay productos.\n");
            break;

        case 6:
            printf("Salie\n");
            break;

        default:
            printf("opción inválida.\n");
        }

    } while (opcion != 6);

    return 0;
}
