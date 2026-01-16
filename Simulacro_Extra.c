// main.c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CIUDADANOS 100

int contador_global = 0;

typedef struct {
    char ID[31];
    bool color;       // blanco=true, negro=false
    char Nombre[31];
} Servicio_Militar;

static void trim_newline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') s[n - 1] = '\0';
}

static bool read_line(const char *prompt, char *out, size_t out_sz) {
    printf("%s", prompt);
    if (!fgets(out, (int)out_sz, stdin)) return false;
    trim_newline(out);
    return true;
}

static void Registro(Servicio_Militar ciudadano[]) {
    if (contador_global >= MAX_CIUDADANOS) {
        printf("No se puede registrar: capacidad maxima (%d) alcanzada.\n", MAX_CIUDADANOS);
        return;
    }

    printf("Registro de nuevo ciudadano\n");

    if (!read_line("Identificador del ciudadano: ", ciudadano[contador_global].ID, sizeof(ciudadano[contador_global].ID)))
        return;

    if (!read_line("Nombre del ciudadano: ", ciudadano[contador_global].Nombre, sizeof(ciudadano[contador_global].Nombre)))
        return;

    ciudadano[contador_global].color = (contador_global % 2 == 0);
    contador_global++;
}

static void Guardar_Registros(const Servicio_Militar ciudadano[]) {
    FILE *fp = fopen("datos.txt", "w");
    if (!fp) {
        perror("Error al guardar datos");
        return;
    }

    for (int i = 0; i < contador_global; i++) {
        // Formato: ID|color|Nombre
        // Nota: esto asume que ID/Nombre no contienen '|'
        fprintf(fp, "%s|%d|%s\n",
                ciudadano[i].ID,
                ciudadano[i].color ? 1 : 0,
                ciudadano[i].Nombre);
    }

    fclose(fp);
    printf("Guardado: %d registros.\n", contador_global);
}

static void Leer_Registro(Servicio_Militar ciudadano[]) {
    FILE *fp = fopen("datos.txt", "r");
    if (!fp) {
        perror("Error al leer archivo");
        return;
    }

    contador_global = 0;

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (contador_global >= MAX_CIUDADANOS) {
            printf("Advertencia: se alcanzo el maximo (%d). Se ignoraran mas registros.\n", MAX_CIUDADANOS);
            break;
        }

        Servicio_Militar tmp = {0};
        int tmp_color = 0;

        // Lee ID hasta '|', luego color, luego Nombre hasta fin de linea
        if (sscanf(line, "%30[^|]|%d|%30[^\n]", tmp.ID, &tmp_color, tmp.Nombre) == 3) {
            tmp.color = (tmp_color != 0);
            ciudadano[contador_global++] = tmp;
        }
    }

    fclose(fp);
    printf("Leido: %d registros.\n", contador_global);
}

static void clear_stdin_line(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main(void) {
    Servicio_Militar ciudadano[MAX_CIUDADANOS] = {0};
    int opcion = 0;

    do {
        printf("\nSeleccione la operacion a realizar:\n"
               "1) Crear un nuevo registro\n"
               "2) Leer los registros\n"
               "3) Guardar cambios\n"
               "4) Salir\n"
               "Opcion: ");

        if (scanf("%d", &opcion) != 1) {
            clear_stdin_line();
            printf("Entrada invalida\n");
            continue;
        }
        clear_stdin_line(); // consume el '\n' para que fgets funcione bien

        switch (opcion) {
            case 1:
                Registro(ciudadano);
                break;
            case 2:
                Leer_Registro(ciudadano);
                break;
            case 3:
                Guardar_Registros(ciudadano);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
