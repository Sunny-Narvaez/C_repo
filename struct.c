#include <stdio.h>
#include <string.h>

typedef struct{
    int id;
    char color[10];
    char nombre[50];
} Ciudadano;

int main(){
    Ciudadano v[3];

    for (int i = 0; i < 3; i++){
        if (i%2 == 0)
            strcpy(v[i].color,"Blanca");
        else{
            strcpy(v[i].color,"Negra");
        }

    }
    return 0;
}