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
        int i = 0;
        while(*(buffer + i) != '\0' && *(buffer + i) != '\n'){
            if(isdigit(*(buffer + i)) == 0){
                isDigit = 0;
            }
            i++;
        }
        if(isDigit == 1){
            sum += atoi(buffer);
        }else{
            if(*(buffer + i) == '\n'){
                fprintf(stderr, "invalid input %s", buffer);
            }else{
                fprintf(stderr, "invalid input %s\n", buffer);
            }
        }
    }
    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
