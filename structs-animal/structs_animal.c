#include <stdio.h>
#include <string.h>

typedef struct{
    char nombre[20];
    int numero_de_patas;
    char color_de_pelo[20];
    char familia[20];
} Animal;

void registro_de_animales(Animal animales[], int n){
    for (int i = 0; i < n; i++){
        printf("Cual es el nombre del animal?\n");
        scanf(" %[^\n]", animales[i].nombre);
        printf("Cuantas patas tiene el animal?\n");
        scanf("%d", &animales[i].numero_de_patas);
        printf("Que familia pertenece?\n");
        scanf(" %[^\n]",animales[i].familia);
        printf("De que color de pelo es el animal %s\n", animales[i].nombre);
        scanf(" %[^\n]", animales[i].color_de_pelo);
}
}
void imprimir_animales(Animal animales[], int no_animales){
        for(int j = 0; j < no_animales; j++){
        printf("El animal numero %d, %s tiene %d patas, es de color de pelo %s y pertenece a la familia %s\n",j+1, animales[j].nombre, animales[j].numero_de_patas, animales[j].color_de_pelo, animales[j].familia);
    }
}

int main (void){
    int no_animales;
    printf("Cuantos animales vas a registrar?\n");
    scanf("%d", &no_animales);
    Animal animales[no_animales];
    registro_de_animales(animales, no_animales);
    imprimir_animales(animales, no_animales);
    return 0;
}
