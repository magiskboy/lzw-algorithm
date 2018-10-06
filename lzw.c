#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void usage(){
    puts("lzw - LZW compression for text files ONLY\n\
            usage : lzw (-h | -c | -x) file1 [file2 file3 ...]\n\
            where :     -h  prints this message\n\
            -c  compresses the file(s)\n\
            -x  extracts the file(s)");
    exit(1);
}

int main(int argc, char** argv){
    extern int lzw_compress();
    extern void lzw_extract();

    if ((argc == 1) || !(strcmp("-h",argv[1]))){
        usage();
    }

    if (argc > 2){
        int tmp = 2;

        while (tmp < argc){
            if (!strcmp("-c",argv[1])){
                printf("Compressing %s ... ", argv[tmp]);
                printf("(%d%%) done\n", lzw_compress(argv[tmp]));
            }
            else if (!strcmp("-x", argv[1])){
                printf("Extracting %s ... ", argv[tmp]);
                lzw_extract(argv[tmp]);
                printf("Done\n");
            }
            else usage();
            ++tmp;
        }
    }
    else usage();

    return 0;
}
