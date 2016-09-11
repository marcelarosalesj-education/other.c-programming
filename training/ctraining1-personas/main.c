#include <stdio.h>

struct datos{
    char nombre[50];
    int edad;
    char telefono[20];
};

int main(){
    int num;
    printf("Num de personas:\n");
    scanf("%d", &num);
    struct datos lista_personas[num];
    int i;
    for(i = 0; i < num; i++){
        printf("Persona %d:\n", i+1);
        printf("Nombre: ");
        scanf("%s", &lista_personas[i].nombre);
        printf("Edad: ");
        scanf("%d", &lista_personas[i].edad);
        printf("Telefono: ");
        scanf("%s", &lista_personas[i].telefono);
    }
    printf("-- Datos de las personas --\n");
    for(i = 0; i < num; i++){
        printf("Persona %d:\n", i+1);
        printf("Nombre: %s \tEdad: %d \tTelefono: %s \n", lista_personas[i].nombre, lista_personas[i].edad, lista_personas[i].telefono);
    }
    return 0;
}
