#include <stdio.h>

int main(int argc, const char* argv[]) {
    if(argc < 3)
        return 0;

    FILE* fp_src = fopen(argv[1], "r");
    FILE* fp_dst = fopen(argv[2], "w");
    
    int c;
    while((c = fgetc(fp_src)) != EOF){
        fprintf(fp_dst, "%c", c);
    }

    fclose(fp_src);
    fclose(fp_dst);

    return 0;
}
