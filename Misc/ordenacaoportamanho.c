#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 

Crie um programa para ordenar um conjunto de strings pelo seu tamanho. Seu programa deve receber um conjunto de strings e retornar este mesmo conjunto ordenado pelo tamanho 
as palavras, se o tamanho das strings for igual, deve-se manter a ordem original do conjunto.


Entrada:
A primeira linha da entrada possui um único inteiro N, que indica o número de casos de teste. Cada caso de teste poderá conter de 1 a 50 strings inclusive, 
e cada uma das strings poderá conter entre 1 e 50 caracteres inclusive. Os caracteres poderão ser espaços, letras, ou números.


Saída:
A saída deve conter o conjunto de strings da entrada ordenado pelo tamanho das strings. Um espaço em branco deve ser impresso entre duas palavras.

*/

void insertionSort(char arr[][50], int n) {
    for (int i = 1; i < n; i++) {
        char key[50];
        strcpy(key, arr[i]);     
        int j = i - 1;

        while (j >= 0 && strlen(arr[j]) < strlen(key)) {
            strcpy(arr[j + 1], arr[j]);
            j--;
        }
        strcpy(arr[j + 1], key);    
    }
}

void sizeSorter(){
    char stringCrua[2600];
    char matriz[50][50];
    fgets(stringCrua, sizeof(stringCrua), stdin);
    stringCrua[strcspn(stringCrua, "\n")] = '\0';
    char *token = strtok(stringCrua, " ");
    int i = 0;
    while (token != NULL) {
        strcpy(matriz[i], token);   
        token = strtok(NULL, " ");  
        i++;
    }
    insertionSort(matriz, i);
    for(int p = 0; p < i; p++){
        printf("%s", matriz[p]);
        if(p < i){
            printf(" ");
        }
    }
    memset(matriz, 0, sizeof(matriz));
}



int main(){

    int nCasosTeste;
    scanf("%d", &nCasosTeste);
    getchar();
    for(int i = 0; i < nCasosTeste; i++){
        sizeSorter();
        printf("\n");
    }
    return 0;
}