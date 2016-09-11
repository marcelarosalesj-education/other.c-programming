#include <stdio.h>
#include <stdlib.h>

#define MSG                         "Ohh my God, They killed Kenny"
#define THE_ENIGMA_MSG "o'<#,2#,\"'12#<#12#<+#,1}(#<+},\"}<3,<!-00#-<}<*-1<',1203!2-0#1<!-,<#*<1'%3'#,2#<!-\"'%-V<c`_I`orIabIPLIU<7<1'<#0#1<#*<M0-<%},}0}1<3,<.0#+'-=<d#'*<^g=\0"

#define FIRST_PRINTABLE_SYMBOL      0x20
#define LAST_PRINTABLE_SYMBOL       0x7E
#define NUMBER_OF_SYMBOLS           (LAST_PRINTABLE_SYMBOL - FIRST_PRINTABLE_SYMBOL)
#define STRING_MAX_LENGHT           500

#define SEED                        216

void vf_encryptMsg(char *cp_dest, char *cp_source, unsigned char seed);
void vf_dencryptMsg(char *cp_dest, char *cp_source, unsigned char seed);

int main()
{
   char *encrypted_msg = (char *)malloc(STRING_MAX_LENGHT);
   char *recovered_msg  = (char *)malloc(STRING_MAX_LENGHT);

   vf_encryptMsg(encrypted_msg, MSG, SEED);
   printf("Original Msg: %s\nEncrypted Msg: %s\n",MSG,encrypted_msg);

   vf_dencryptMsg(recovered_msg, encrypted_msg, SEED);
   printf("Recovered message: %s\n",recovered_msg);

   vf_dencryptMsg(recovered_msg, THE_ENIGMA_MSG, SEED);
   printf("Recovered message: %s\n",recovered_msg);


   return 0;
}

void vf_encryptMsg(char *cp_dest, char *cp_source, unsigned char seed) {
   short int temp;
   seed = seed % NUMBER_OF_SYMBOLS;
   while(*cp_dest = *cp_source){
      temp = (short int)(*cp_source) + seed;
      temp = (temp > LAST_PRINTABLE_SYMBOL) ? FIRST_PRINTABLE_SYMBOL + temp - LAST_PRINTABLE_SYMBOL : temp;
      *cp_dest = (char)temp;
      ++cp_dest;
      ++cp_source;
   }
}


void vf_dencryptMsg(char *cp_dest, char *cp_source, unsigned char seed){
    short int temp;
    seed = seed % NUMBER_OF_SYMBOLS;
    //while( *cp_dest = *cp_source ){
    int i;
    for(i=0; i<200; i++){
        if( *cp_source == '\0') break;
        if(*cp_source == '\\' && *(cp_source+1)== '"' ){
            cp_source++;
        }
        temp = (short int)(*cp_source) - seed;
        temp = (temp < FIRST_PRINTABLE_SYMBOL) ? LAST_PRINTABLE_SYMBOL - (seed - ((*cp_source) - FIRST_PRINTABLE_SYMBOL)) : temp;
        *cp_dest = (char)temp;
        ++cp_dest;
        ++cp_source;
   }
   *cp_dest = (char)'\0';
}

