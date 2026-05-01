#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
typedef struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
}Cliente;

float calcularCostoTotal(Producto prod);

int main(){

    srand(time(NULL));

    int cantidadClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d",&cantidadClientes);
    getchar(); // Limpiamos el buffer para que el próximo gets no falle

    Cliente *clientes = (Cliente *) malloc(cantidadClientes * sizeof(Cliente));
    
    for (int i = 0; i < cantidadClientes; i++)
    {
        clientes[i].ClienteID = i +1;//cargo el id del cliente

        printf("\n--- Carga del Cliente ID: %d ---\n", clientes[i].ClienteID);
        printf("Nombre del cliente: ");
        char Buff[100];
        fflush(stdin);//Limpio el buffer por si acaso
        gets(Buff);

        int longitud = strlen(Buff) + 1;
        clientes[i].NombreCliente = (char *) malloc(longitud * sizeof(char));
        strcpy(clientes[i].NombreCliente, Buff);//copio el NOMBRE del cliente

        clientes[i].CantidadProductosAPedir = rand() % 5 + 1; // Genero la cantidad de productos que va a pedir de manera aletario con el rand % 5 + 1
        clientes[i].Productos = (Producto *) malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j + 1; // ID de producto (1, 2, 3...)
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1; // Cantidad entre 1 y 10 de productos que llevara el cliente
            //Tipos de productos
            int indiceTipo = rand() % 5; // Genero un numero aleatorio entre 0 y 4 para elegir el producto del arreglo de productos
            clientes[i].Productos[j].TipoProducto = TiposProductos[indiceTipo];
            //Precio unitario entre 10 y 100
            clientes[i].Productos[j].PrecioUnitario = (rand() % 91) + 10; //numero aleatorio con restriccion
        }
    }
    printf("\n--- LISTADO DE VENTAS ---\n");
    for (int i = 0; i < cantidadClientes; i++) {
        float totalGastoCliente = 0; // Para sumar todos los productos de este cliente
        
        printf("\nCliente: %s (ID: %d)", clientes[i].NombreCliente, clientes[i].ClienteID);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            // ACÁ USAMOS LA FUNCIÓN:
            // Le pasamos el producto actual: clientes[i].Productos[j]
            float subtotal = calcularCostoTotal(clientes[i].Productos[j]);
            
            // Vamos sumando al total del cliente
            totalGastoCliente += subtotal;

            printf("\n  -> %s: %d unidades x $%.2f = Subtotal: $%.2f", 
                   clientes[i].Productos[j].TipoProducto,
                   clientes[i].Productos[j].Cantidad,
                   clientes[i].Productos[j].PrecioUnitario,
                   subtotal);
        }
        
        printf("\nTOTAL A PAGAR: $%.2f\n", totalGastoCliente);
    }

    //Liberacion de memoria
    for (int i = 0; i < cantidadClientes; i++) {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}

float calcularCostoTotal(Producto prod){
    return prod.Cantidad * prod.PrecioUnitario;
}