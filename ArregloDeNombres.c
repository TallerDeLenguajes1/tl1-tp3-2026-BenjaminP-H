#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 5

void MostrarPersonas(char *nombres[TAM]);
int BuscarNombre(char *nombres[TAM], char *nombreBuscado);

int main()
{
    char *nombres[TAM]; //arreglo tipo puntero

    char Buff[50];// sirve para almacenar cadenas de caracteres

    printf("--- Ingrese 5 Nombres ---\n");

    for (size_t i = 0; i < TAM; i++)
    {
        printf("Nombre [%i]: ", i);
        gets(Buff);// mejor que scanf para leer cadenas de caracteres

        // --- RESERVA DINÁMICA (EL HEAP) ---

        int longitud = strlen(Buff) + 1; // +1 para el \0
        nombres[i] = (char *) malloc(longitud * sizeof(char));//reserve memoria para la cadena
        strcpy(nombres[i], Buff);// escribe la cadena en la memoria reservada en este caso en el arreglo nombres
    }
    
    MostrarPersonas(nombres);

    char nombreBuscado[50];
    printf("\nIngrese el nombre a buscar: ");
    gets(nombreBuscado);
    BuscarNombre(nombres, nombreBuscado);

    return 0;
}

void MostrarPersonas(char *nombres[TAM]){
    printf("\n--- Listado de Personas ---\n");
    for (int i = 0; i < TAM; i++)
    {
        // %s sigue la dirección del puntero e imprime la cadena hasta el \0
        printf("ID %d: %s\n", i, nombres[i]);
    }
}

int BuscarNombre(char *nombres[TAM], char *nombreBuscado){
    for (int i = 0; i < TAM; i++)
    {
        if (strstr(nombres[i], nombreBuscado) != NULL) // Esta función busca una "subcadena" (la palabra clave) dentro de una cadena más grande (el nombre guardado en mi vector)
        {
            printf("\nEl nombre %s se encuentra en la posicion %d", nombreBuscado, i);
            return i;
        }
    }
    printf("\nEl nombre %s no se encuentra en la lista", nombreBuscado);
    return -1;
}