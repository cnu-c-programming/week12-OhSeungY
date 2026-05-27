#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* fp = fopen("config.txt", "r");
    char buffer[256];
    char value[64];
    int count = 1;
   
    while(feof(fp) == 0){
        fgets(buffer, sizeof(buffer), fp);
        if(count == 1){
            sscanf(buffer, "InputFileName=%s", value);
            strcpy(config_ptr->InputFileName, value);
            count++;
        }else if(count == 2){
            sscanf(buffer, "Options=%s", value);
            config_ptr->Options = atoi(value);
            count++;
        }else if(count == 3){
            sscanf(buffer, "SectionName=%s", value);
            strcpy(config_ptr->SectionName, value);
            count++;
        }else if(count == 4){
            sscanf(buffer, "Address=%s", value);
            config_ptr->Address = strtol(value, NULL, 16);
            
        }
    }
    fclose(fp);
    
}

int main(int argc, const char* argv[]) {
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n", 
        config.InputFileName, 
        config.Options,
        config.SectionName,
        config.Address);
    return 0;
}

