#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    if(argc < 3)
        return 0;

    FILE* fp = fopen(argv[1], "r");
    const char* target_str = argv[2];
    char buffer[256];

    while(feof(fp) == 0){
        fgets(buffer, sizeof(buffer), fp);
        if(strchr(buffer, *target_str) == 0){
            printf("%s\n", buffer);
        }
    }

    fclose(fp);

    return 0;
}
