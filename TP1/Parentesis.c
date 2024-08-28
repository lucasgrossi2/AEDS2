#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


bool isFim(char *palavra) {
    return strcmp(palavra, "FIM") == 0; // se for FIM, retorna 1, se não for FIM, retorna 0
}
//strcmp: 0 if strings are equal
void parCheck(){
    char string[1000];
    int firstPar = 0; // Se ), 1. Se (, 2.
    int firstCheck = 0;
    scanf("%[^\n]%*c", string);

    if(isFim(string) == 1){
        return;
    } else {
        for(int i = 0; i < strlen(string) && firstCheck == 0; i++){
            if(string[i]==')'){
                firstPar = 1;
                firstCheck++;
            } else if(string[i]=='('){
                firstPar = 2;
                firstCheck++;
            }
        }
        if(firstPar == 1){;
            printf("incorreto\n");
        } else {
            int balanco = 0;
            for(int j = 0; j < strlen(string); j++){
                if(string[j]==')'){
                    balanco--;
                } else if(string[j]=='('){
                    balanco++;
                }
            }
            if(balanco == 0){
                printf("correto\n");
            } else {
                printf("incorreto\n");
            }
        }
        parCheck();
    }
}

int main(){
    parCheck();
} 

