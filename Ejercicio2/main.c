/*
The program gets two parameters: a file name(F), a string(S), 
composed by one word, as input. Then it has to display, for 
each line of text file F the frequency of string S (how many 
times S appear in the line)

Note: the last character should be an enter.
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true}	bool;

int main (int argc, char * argv[]) {
	FILE *addr;
	char c;
	int count = 0, pos = 0;
	bool last_one = false;
	
	if (argc != 3) {
		printf(" There should be 2 parameters: <file> <string>\n");
		exit(1);
	}
	addr = fopen(argv[1], "r");
	
	if (addr != NULL) {
		while( (c = fgetc(addr)) != EOF) {
			//printf (" LINEA %c %c\n", c, argv[2][pos]);
			if (c == argv[2][pos]) {
				pos++;
				last_one = true;
				
				//printf("%c %d\n" , argv[2][pos],pos);
				if (argv[2][pos] == '\0') {

					if(last_one == true ) {
						count++;
						pos = 0;
					}
					
				}
			} else {
				last_one = false;
				pos = 0;
			}
			
			// print every Enter
			if (c == '\n') {
				printf("RESULT: %d\n",count);
				count = 0;
			}
			
		} // end of while
		
		if(fclose(addr) == EOF) {
			printf("Error closing source file.\n");
    		exit(1);
		}
	}
	return 0;
}