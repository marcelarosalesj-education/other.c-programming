#include <stdio.h>
#include <conio.h>

struct str_process{
    unsigned char activate;
    unsigned char isRunning;
    unsigned int start_time;
    unsigned int stop_time;
    void (*ptr_fun)(void);
};

void funct0(void){
    printf(" Funcion 0\n");
}

void funct1(void){
    printf(" Funcion 1\n");
}

void funct2(void){
    printf(" Funcion 2\n");
}

void funct3(void){
    printf(" Funcion 3\n");
}

int main(void){
    struct str_process arr[4];
    // arr[0]
    arr[0].activate = 0;
    arr[0].isRunning = 0;
    arr[0].start_time = 2;
    arr[0].stop_time = 4;
    arr[0].ptr_fun = funct0;
    // arr[1]
    arr[1].activate = 0;
    arr[1].isRunning = 0;
    arr[1].start_time = 1;
    arr[1].stop_time = 3;
    arr[1].ptr_fun = funct1;
    // arr[2]
    arr[2].activate = 0;
    arr[2].isRunning = 0;
    arr[2].start_time = 3;
    arr[2].stop_time = 5;
    arr[2].ptr_fun = funct2;
    // arr[3]
    arr[3].activate = 0;
    arr[3].isRunning = 0;
    arr[3].start_time = 3;
    arr[3].stop_time = 6;
    arr[3].ptr_fun = funct3;

    int time = 0;
    int i;

    //printf("antes while\n");
    //(*arr[1].ptr_fun)();

    while( !kbhit() ){
        for(i=0; i<4; i++){
            //printf("en if %d\n", i);
            //printf("start %d, stop %d. TIME %d\n", arr[i].start_time, arr[i].stop_time, time );
            if( arr[i].start_time <= time && arr[i].stop_time >= time ){
                arr[i].activate = 1;
                arr[i].isRunning = 1;
                //(*arr[i].ptr_fun)();
                (*arr[i].ptr_fun)();
            } else {
                arr[i].activate = 0;
                arr[i].isRunning = 0;
            }
        }
        time++;
        sleep(1);
        printf("Time:  %d\n", time);

        if( time == 8)
            break;
    }
    return 0;
}
