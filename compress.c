#include "compress.h"

int lzw_compress(char *file){
    FILE *inputfd, *outputfd;
    int location;
    long int inchar = 0L, outchar = 0L;
    unsigned char base_code, char_read;
    extern void init_table(), addcode();
    extern int lookup(), table_not_full;

    inputfd = fopen(file,"r");
    if (inputfd == NULL){
        fprintf(stderr,"File %s caused an error\n",file);
        exit(-1);
    }

    outputfd = fopen("output.zip","w+");
    if (outputfd == NULL){
        fprintf(stderr,"File output.par caused an error\n");
        exit(-1);
    }

    init_table();
    GETCHAR(base_code);
    inchar++;
    while (GETCHAR(char_read)){
        inchar++;
        if (lookup(char_read,base_code, &location)){
            base_code = (unsigned char)location;
        }
        else{
            PUTCHAR(base_code);
            outchar++;
            if (table_not_full == 1){
                addcode(char_read, base_code, location);
            }
            base_code = char_read;
        }
    }

    PUTCHAR(base_code);
    outchar++;
    fclose(outputfd);
    fclose(inputfd);

    return((int)(((float)outchar/(float)inchar) * 100.0));
}
