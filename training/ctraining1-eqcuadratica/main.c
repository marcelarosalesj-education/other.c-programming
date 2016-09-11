#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, temp, res;
    char im[1];
    printf("Ecuacion cuadratica:\n");
    printf("Num imaginarios (S/N): ");
    scanf("%s", im);
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    // Empieza a resolver la ecuacion
    temp = b*b-4*a*c;
    printf("temp %f im %s \n", temp, im);
    if(temp < 0 && im[0] == 'N'){
        printf("Error: No es posible calcular el resultado.");
        return 1;
    } else if(temp < 0 && im[0] == 'S'){
        temp=(-1)*temp; // temp is going to be im from here
        temp = sqrt(temp)/(2*a); // Im Part
        res = -b/(2*a); // Real part
        printf("R1: %f+%fi ", res, temp);
        printf("R2: %f-%fi \n", res, temp);
    } else {
        res = -b+sqrt(temp)/(2*a);
        printf("R1: %f ", res);
        res = -b-sqrt(temp)/(2*a);
        printf(" R2: %f \n", res);
    }


    return 0;
}
