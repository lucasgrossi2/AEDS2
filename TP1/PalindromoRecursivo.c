#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isFim(char *palavra) {
    return strcmp(palavra, "FIM") == 0;
}

bool isPal(char *palavras){
    int len = strlen(palavras);
    int n = len / 2;
    bool resp = true;
    for(int i  = 0; i < n; i++) {
        if(palavras[i] != palavras[len - i - 1]) {
            resp = false;
            break;
        }
    }
    return resp;
}

// Função recursiva para imprimir se a string é um palíndromo
void imprimePal(char palavras[][1000], int i, int entrada) {
    if (i < entrada) {
        if (isPal(palavras[i])) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        imprimePal(palavras, i + 1, entrada);
    }
}

// Função recursiva para ler entradas até encontrar "FIM"
int lePalavras(char palavras[][1000], int entrada) {
    scanf("%[^\n]%*c", palavras[entrada]);
    if (isFim(palavras[entrada])) {
        return entrada;
    } else {
        return lePalavras(palavras, entrada + 1);
    }
}

int main() {
    char palavras[1000][1000];
    int entrada = lePalavras(palavras, 0); // Ler entradas recursivamente
    imprimePal(palavras, 0, entrada);      // Imprimir resultados recursivamente
    return 0;
}
