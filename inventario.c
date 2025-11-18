#include <stdio.h>
#include <math.h>
#include "inventario.h"

void ingresarProductos(char nombres[][LONG_NOMBRE], float precios[], int *cantidad) {
    printf("Ingrese la cantidad de productos (max %d): ", MAX_PRODUCTOS);
    scanf("%d", cantidad);
    
    if (*cantidad > MAX_PRODUCTOS) {
        printf("Error: No puede exceder %d productos. Se limitara a %d.\n", MAX_PRODUCTOS, MAX_PRODUCTOS);
        *cantidad = MAX_PRODUCTOS;
    }
    
    for (int i = 0; i < *cantidad; i++) {
        printf("\nProducto %d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", nombres[i]);
        printf("Precio: ");
        scanf("%f", &precios[i]);
    }
}

float calcularPrecioTotal(float precios[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}

void encontrarExtremos(char nombres[][LONG_NOMBRE], float precios[], int cantidad, char masCaro[], char masBarato[]) {
    if (cantidad == 0) return;
    
    float maxPrecio = precios[0];
    float minPrecio = precios[0];
    
    // Copiar el primer nombre sin usar strcpy
    int j = 0;
    while (nombres[0][j] != '\0') {
        masCaro[j] = nombres[0][j];
        masBarato[j] = nombres[0][j];
        j++;
    }
    masCaro[j] = '\0';
    masBarato[j] = '\0';
    
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > maxPrecio) {
            maxPrecio = precios[i];
            // Copiar nombre manualmente
            j = 0;
            while (nombres[i][j] != '\0') {
                masCaro[j] = nombres[i][j];
                j++;
            }
            masCaro[j] = '\0';
        }
        if (precios[i] < minPrecio) {
            minPrecio = precios[i];
            // Copiar nombre manualmente
            j = 0;
            while (nombres[i][j] != '\0') {
                masBarato[j] = nombres[i][j];
                j++;
            }
            masBarato[j] = '\0';
        }
    }
}

float calcularPromedio(float precios[], int cantidad) {
    if (cantidad == 0) return 0;
    float total = calcularPrecioTotal(precios, cantidad);
    return total / cantidad;
}

int buscarProducto(char nombres[][LONG_NOMBRE], float precios[], int cantidad, char nombreBuscado[]) {
    for (int i = 0; i < cantidad; i++) {
        // Comparar strings manualmente sin strcmp
        int j = 0;
        int igual = 1;
        while (nombres[i][j] != '\0' && nombreBuscado[j] != '\0') {
            if (nombres[i][j] != nombreBuscado[j]) {
                igual = 0;
                break;
            }
            j++;
        }
        // Verificar que ambos strings terminaron al mismo tiempo
        if (igual && nombres[i][j] == '\0' && nombreBuscado[j] == '\0') {
            return i;
        }
    }
    return -1;
}

void mostrarMenu() {
    printf("\nSISTEMA DE GESTION DE INVENTARIO\n");
    printf("1. Ingresar productos\n");
    printf("2. Calcular precio total del inventario\n");
    printf("3. Encontrar producto mas caro y mas barato\n");
    printf("4. Calcular precio promedio\n");
    printf("5. Buscar producto por nombre\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
}