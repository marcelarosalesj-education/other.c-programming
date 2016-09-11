#include <stdio.h>

struct persona{
    char nombre[20]; //20*1
    int edad;//4
    double estatura;//8
    double peso;//8
    float otros[2] //4*2
} pers1;

union datos{
    int d1;
    char d2;
    char d3;
    double d4;
    int d5;
} datos_ej;

struct dobchar {
    char ch1;
    char ch2;
}dobchar;

union data_union{
    int a;
    char as[4];
    struct dobchar dch[2];
}data_u;

struct data_structure{
    int a;
    char a0;
    char a1;
    char a2;
    char a3;
}data_s;

int main(void){
    char a = "A";
    int b = 15;
    float c = 3.14;
    double d = 0.12345;
    long double e = 1234.5678;
    char arr_char[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int arr_int[] = {10,20,30,40,50,60,70,80,90,100};
    double arr_dou[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7};

    printf("Sizes of variables \n");
    printf("Size of a: %d \n", sizeof(a));
    printf("Size of b: %d \n", sizeof(b));
    printf("Size of c: %d \n", sizeof(c));
    printf("Size of d: %d \n", sizeof(d));
    printf("Size of e: %d \n", sizeof(e));
    printf("Size of arr_char: %d \n", sizeof(arr_char));
    printf("Size of arr_int: %d \n", sizeof(arr_int));
    printf("Size of arr_dou: %d \n", sizeof(arr_dou));
    printf("Size of pers1: %d \n", sizeof(pers1));
    printf("Size of datos_ej: %d \n", sizeof(datos_ej));

    printf("Examples with Union \n");
    data_u.a=2663862662; // 0x9E C7 51 86
    printf("Val a: %x \n", data_u.a);
    data_u.as[0]=0xA;
    printf("Val a: %x \n", data_u.a);
    data_u.as[1]=0xB;
    printf("Val a: %x \n", data_u.a);
    data_u.as[2]=0xC;
    printf("Val a: %x \n", data_u.a);
    data_u.as[3]=0xD;
    printf("Val a: %x \n", data_u.a);
    data_u.dch[0].ch1=0x3344;
    printf("Val a: %x \n", data_u.a);
    data_u.dch[1].ch1=0x6677;
    printf("Val a: %x \n", data_u.a);


    printf("Examples with Structure \n");
    data_s.a=0x925A7D8E; // 0x92 5A 7D 8E
    printf("Val a: %x \n", data_s.a);
    data_s.a0=0xA;
    printf("Val a: %x \n", data_s.a);
    data_s.a1=0xB;
    printf("Val a: %x \n", data_s.a);
    data_s.a2=0xC;
    printf("Val a: %x \n", data_s.a);
    data_s.a3=0xD;
    printf("Val a: %x \n", data_s.a);


    printf("Size of a Structure \n");
    struct persona pers2[2];
    printf("1) Size of pers2: %d \n", sizeof(pers2[0]));
    int tam;
    printf(" > %d \n > %d \n", &pers2[0], &pers2[1]);
    tam = (int)&pers2[1] - (int)&pers2[0];
    printf("2) Size of pers2: %d \n", tam);
    return 0;
}
