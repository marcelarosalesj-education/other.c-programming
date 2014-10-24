/*
Create a simple C program, main.c, able to get the number of 
words of a text file. Text file has to be passed as parameter 
in the command line, and copy it in the src directory.

*/

#include<stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){    
	FILE *from, *to;	
	char ch;
	int count = 0, lastc, c;
    
	if(argc!=2) {
		printf("It should be two parameters\n");
		exit(1);
	}

    if((from = fopen(argv[1], "r")) == NULL) {
    	printf("Error opening source file.\n");
   	exit(1);
    }

    if((to = fopen("./src/copy.txt", "w")) == NULL) {
      printf("Error creating destination file.\n");
      exit(1);
    }
	
	/* 	Copying the first letter
		Knowing the 1st letter is needed to make the comparison and know if 
		the a word is ending.	*/
	ch = fgetc(from);
	lastc = ch;
	fputc(ch, to);
	
	// Copying the rest of the letters    
    if (from != NULL){
       while( (ch = fgetc(from)) != EOF){
			// Copying char by char
    		fputc(ch, to);
			
			// Counting 
    		c = ch;
    		// (Uppercase OR Lowercase) AND a followed by a (Blank space OR a Colon OR enter )
    		if(((65 <= lastc && lastc <= 90) || (97 <= lastc && lastc <= 122)) && (c == 32 || c == 58 || c == 10)) {	                	
				count++;
			}
			lastc = c;
    	}

    	if(fclose(from) == EOF) {
    		printf("Error closing source file.\n");
    		exit(1);
    	}
	}

    if(fclose(to)==EOF) {
    	printf("Error closing destination file.\n");
   	exit(1);
    }
    
    printf("RESULT: %d \n", count);

    return 0;
}
