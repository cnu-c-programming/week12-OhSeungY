#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        return 0;
    }

    int sum = 0;
    char buffer[32];

    while(feof(fp) == 0){
        fgets(buffer, sizeof(buffer), fp);
        int isDigit = 1;
        int str_length = strlen(buffer) - 1;
        for(int i=0; i<str_length; i++){
            if(isdigit(*(buffer + i)) == 0){
                isDigit = 0;
            }
        }
        if(isDigit == 1){
            sum += atoi(buffer);
        }else{
            fprintf(stderr, "invalid input %s", buffer);
        }
    }
    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
