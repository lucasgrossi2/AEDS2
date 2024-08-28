#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <float.h>
#include <time.h>

bool isFim(char *palavra) {
    return strcmp(palavra, "FIM") == 0; // verifica se é o fim das entraadas
}


bool isPal(char *palavras){
    int len = strlen(palavras);
    int n = len/2;
    bool resp = true;
    for(int i  = 0;i < n;i++){ // vai checando se o char na posição x é igual ao char em sua posição oposta
        if(palavras[i] != palavras[len-i-1] ){
            resp = false;
            i = n;
        }
    }
    return resp;
}

void imprimePal(char palavras[][1000], int entrada){
    for(int i = 0; i < entrada;i++){ 
        if(isPal(palavras[i])){ // imprime se a string é ou não palindromo
            printf("SIM\n");
        }else{
            printf("NAO\n");
        }
    }
}


int main() {

    char palavras[1000][1000];
    int entrada = 0;

    do {
        scanf("%[^\n]%*c", palavras[entrada]);
    } while (!isFim(palavras[entrada++])); // recebe as entradas
    entrada--;


    imprimePal(palavras,entrada);



    return 0; //retorna 0
}
