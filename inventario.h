#define MAX_PRODUCTOS 10
#define LONG_NOMBRE 50

int ingresarProductos(char nombres[][LONG_NOMBRE], float precios[], int cantidad);
float calcularPrecioTotal(float precios[], int cantidad);
void encontrarExtremos(char nombres[][LONG_NOMBRE], float precios[], int cantidad, char masCaro[], char masBarato[]);
float calcularPromedio(float precios[], int cantidad);
int buscarProducto(char nombres[][LONG_NOMBRE], float precios[], int cantidad, char nombreBuscado[]);
