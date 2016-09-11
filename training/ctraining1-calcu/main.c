#include <stdio.h>


int main(void){
    float num1, num2, res;
    char oper[1];

    printf("Give me num1: ");
    scanf("%f", &num1);
    printf("num1 = %f \n", num1);
    printf("Give me num2: ");
    scanf("%f", &num2);
    printf("num2 = %f \n", num2);
    printf("Give me the operation +,-,*,/,%,(A)ND,(O)R,(X)OR:");
    scanf("%s", oper);
    printf("oper = %s \n", oper);

    if((oper[0] == 'A' || oper[0] == 'O' || oper[0] == 'X') && (num1>1 || num1<0 || num2>1 || num2<0 ) ){
        printf("Error: For logic operations numbers should be 1 or 0. \n");
        return 1;
    }

    if( (oper[0] == '%') && (!(ceilf(num1) == num1) || !(ceilf(num2) == num2)) ){
        printf("Error: For Module operation numbers should be integers. \n");
        return 2;
    }
/*
    if( (oper[0] == 'A' || oper[0] == 'O' || oper[0] == 'X') && (!(ceilf(num1) == num1) || !(ceilf(num2) == num2)) ){
        printf("Error: For Module operation numbers should be integers. \n");
        return 3;
    }
*/
    if( oper[0] == '/' && num2 == 0 ){
        printf("Error: For Division num2 should be different than 0. \n");
        return 4;
    }

    if(oper[0] == '+'){
        res = num1 + num2;
    } else if(oper[0] =='-'){
        res = num1 - num2;
    }else if(oper[0] =='*'){
        res = num1 * num2;
    }else if(oper[0] =='/'){
        res = num1 / num2;
    }else if(oper[0] =='%'){
        res = (int)num1 % (int)num2;
    }else if(oper[0] =='A'){
        res = num1 && num2;
    }else if(oper[0] =='O'){
        res = num1 || num2;
    }else if(oper[0] =='X'){
        res = (num1 != num2);
    }

    printf("Result: %f \n", res);
    return 0;
}
