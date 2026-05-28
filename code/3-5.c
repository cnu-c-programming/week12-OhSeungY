#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        return 0;
    }

    char buffer[32];
    int sum = 0;
    while(feof(fp) == 0){
        fgets(buffer, sizeof(buffer), fp);
        if(isdigit(*buffer)){
            sum += atoi(buffer);
        }else{
            fprintf(stderr, "invalid input %s", buffer);
        }
    }
    printf("sum: %d\n", sum);

    fclose(fp);

    return 0;
}
