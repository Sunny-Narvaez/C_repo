#include <stdio.h>

#define MAX_PERSONAS 200

void registro(int index[], int *n);
void busqueda(const int index[], int n);

int main(void) {
    int opcion = 0;

    // “Base de datos” simple: index[i] = 1 (blanca) o 0 (negra)
    int index[MAX_PERSONAS];
    int n = 0; // cuántas personas están registradas

    printf("Que necesita el dia de hoy?\n");
    printf("1) Registro de personas\n");
    printf("2) Busqueda de estatus\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            registro(index, &n);
            break;

        case 2:
            busqueda(index, n);
            break;

        default:
            printf("Opcion invalida.\n");
            break;
    }

    return 0;
}

void registro(int index[], int *n) {
    int cantidad;

    printf("Cuantas personas vas a registrar? (max %d): ", MAX_PERSONAS);
    scanf("%d", &cantidad);

    if (cantidad <= 0 || cantidad > MAX_PERSONAS) {
        printf("Cantidad invalida.\n");
        *n = 0;
        return;
    }

    *n = cantidad;

    // Ciudadano 1 = impar -> negra (0), ciudadano 2 = par -> blanca (1)
    for (int i = 0; i < *n; i++) {
        int ciudadano = i + 1;

        if (ciudadano % 2 == 0) {
            index[i] = 1; // blanca
        } else {
            index[i] = 0; // negra
        }
    }

    printf("Registro terminado. Se registraron %d personas.\n", *n);
}

void busqueda(const int index[], int n) {
    int ciudadano;

    if (n == 0) {
        printf("No hay personas registradas. Primero haga el registro.\n");
        return;
    }

    printf("Ingrese el numero de ciudadano (1 a %d): ", n);
    scanf("%d", &ciudadano);

    if (ciudadano < 1 || ciudadano > n) {
        printf("Ciudadano fuera de rango.\n");
        return;
    }

    int i = ciudadano - 1;

    if (index[i] == 1) {
        printf("El ciudadano no. %d recibe bola BLANCA.\n", ciudadano);
    } else {
        printf("El ciudadano no. %d recibe bola NEGRA.\n", ciudadano);
    }
}
