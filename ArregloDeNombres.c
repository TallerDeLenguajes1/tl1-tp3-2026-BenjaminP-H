#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 5

// --- PROTOTIPOS ---
void MostrarPersonas(char *nombres[TAM]);
void BuscaNombrePorId(char *nombres[TAM], int ID);
int BuscaNombrePorPalabra(char *nombres[TAM], char *palabraClave);

int main() {
    char *nombres[TAM]; 
    char Buff[100]; 

    printf("--- Ingrese 5 Nombres ---\n");
    for (int i = 0; i < TAM; i++) {
        printf("Nombre [%d]: ", i);
        fflush(stdin);
        gets(Buff); 

        int longitud = strlen(Buff) + 1;
        nombres[i] = (char *) malloc(longitud * sizeof(char));
        strcpy(nombres[i], Buff);
    }
    
    MostrarPersonas(nombres);

    // --- PARTE 3: INTERFAZ DE USUARIO ---
    int opcion;
    printf("\n--- MENU DE BUSQUEDA ---\n");
    printf("1. Buscar por ID (Posicion)\n");
    printf("2. Buscar por Palabra Clave\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    getchar(); // Limpia el buffer

    if (opcion == 1) {
        int id_buscado;
        printf("Ingrese el ID (0-4): ");
        scanf("%d", &id_buscado);
        BuscaNombrePorId(nombres, id_buscado);
    } 
    else if (opcion == 2) {
        char clave[50];
        printf("Ingrese la palabra clave: ");
        gets(clave);
        int res = BuscaNombrePorPalabra(nombres, clave);
        if (res != -1) {
            printf("Coincidencia encontrada en ID [%d]: %s\n", res, nombres[res]);
        } else {
            printf("-1 (No se encontraron coincidencias)\n");
        }
    }

    // Liberar memoria
    for (int i = 0; i < TAM; i++) {
        free(nombres[i]);
    }

    return 0;
}

// --- IMPLEMENTACIONES ---

void MostrarPersonas(char *nombres[TAM]) {
    printf("\n--- Listado de Personas ---\n");
    for (int i = 0; i < TAM; i++) {
        printf("ID %d: %s\n", i, nombres[i]);
    }
}

void BuscaNombrePorId(char *nombres[TAM], int ID) {
    if (ID >= 0 && ID < TAM) {
        printf("LA PERSONA CON ID [%d] ES: %s\n", ID, nombres[ID]);
    } else {
        printf("no se encontro la persona\n");
    }
}

int BuscaNombrePorPalabra(char *nombres[TAM], char *palabraClave) {
    for (int i = 0; i < TAM; i++) {
        if (strstr(nombres[i], palabraClave) != NULL) {
            return i; 
        }
    }
    return -1; 
}