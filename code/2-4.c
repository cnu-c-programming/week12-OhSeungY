#include <stdio.h>

int main(int argc, const char* argv[]) {
    if(argc < 2){
        return 0;
    }
    FILE* fp = fopen(argv[1], "r");

    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int alphas[26] = {0};

    printf("%d\n", alphas[3]);
    
    int fg;
    while((fg = fgetc(fp)) != EOF){
        switch(fg){
            case 'a' : alphas[0]++; break;
            case 'b' : alphas[1]++; break;
            case 'c' : alphas[2]++; break;
            case 'd' : alphas[3]++; break;
            case 'e' : alphas[4]++; break;
            case 'f' : alphas[5]++; break;
            case 'g' : alphas[6]++; break;
            case 'h' : alphas[7]++; break;
            case 'i' : alphas[8]++; break;
            case 'j' : alphas[9]++; break;
            case 'k' : alphas[10]++; break;
            case 'l' : alphas[11]++; break;
            case 'm' : alphas[12]++; break;
            case 'n' : alphas[13]++; break;
            case 'o' : alphas[14]++; break;
            case 'p' : alphas[15]++; break;
            case 'q' : alphas[16]++; break;
            case 'r' : alphas[17]++; break;
            case 's' : alphas[18]++; break;
            case 't' : alphas[19]++; break;
            case 'u' : alphas[20]++; break;
            case 'v' : alphas[21]++; break;
            case 'w' : alphas[22]++; break;
            case 'x' : alphas[23]++; break;
            case 'y' : alphas[24]++; break;
            case 'z' : alphas[25]++; break;
        }
    }
    for(int i=0; i<26; i++){
        printf("%c: %d\n", alpha[i], alphas[i]);
    }
    fclose(fp);
    
    return 0;
}


