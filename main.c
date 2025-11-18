#include <stdio.h>
#include <math.h>
#include "inventario.h"

int main() {
    char nombres[MAX_PRODUCTOS][LONG_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int cantidad = 0;
    int opcion;
    char nombreBuscado[LONG_NOMBRE];
    char masCaro[LONG_NOMBRE], masBarato[LONG_NOMBRE];
    
    printf("=== SISTEMA DE GESTION DE INVENTARIO ===\n");
    printf("Usando solo stdio.h y math.h\n\n");
    
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                ingresarProductos(nombres, precios, &cantidad);
                break;
                
            case 2:
                if (cantidad > 0) {
                    float total = calcularPrecioTotal(precios, cantidad);
                    printf("Precio total del inventario: $%.2f\n", total);
                } else {
                    printf("No hay productos ingresados.\n");
                }
                break;
                
            case 3:
                if (cantidad > 0) {
                    encontrarExtremos(nombres, precios, cantidad, masCaro, masBarato);
                    
                    // Encontrar índices para mostrar precios
                    int idxCaro = buscarProducto(nombres, precios, cantidad, masCaro);
                    int idxBarato = buscarProducto(nombres, precios, cantidad, masBarato);
                    
                    printf("Producto mas caro: %s - $%.2f\n", masCaro, precios[idxCaro]);
                    printf("Producto mas barato: %s - $%.2f\n", masBarato, precios[idxBarato]);
                } else {
                    printf("No hay productos ingresados.\n");
                }
                break;
                
            case 4:
                if (cantidad > 0) {
                    float promedio = calcularPromedio(precios, cantidad);
                    printf("Precio promedio: $%.2f\n", promedio);
                } else {
                    printf("No hay productos ingresados.\n");
                }
                break;
                
            case 5:
                if (cantidad > 0) {
                    printf("Ingrese el nombre del producto a buscar: ");
                    scanf("%s", nombreBuscado);
                    int indice = buscarProducto(nombres, precios, cantidad, nombreBuscado);
                    if (indice != -1) {
                        printf("Producto encontrado: %s - $%.2f\n", nombres[indice], precios[indice]);
                    } else {
                        printf("Producto no encontrado.\n");
                    }
                } else {
                    printf("No hay productos ingresados.\n");
                }
                break;
                
            case 6:
                printf("Saliendo del sistema...\n");
                break;
                
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);
    
    return 0;
}