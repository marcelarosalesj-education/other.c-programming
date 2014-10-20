#include <stdio.h>

int main(int argc, char *argv[]){
	for(int i=0; i <= (*argv[1]-48); i++){
		printf("%d\t",i);
	}
	
	printf("\nFIN\n");		
}

