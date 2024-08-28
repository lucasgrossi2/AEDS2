#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>


/*Crie um método recursivo que recebe uma string, sorteia duas letras minúsculas aleatórias (código ASCII > 'a' e < 'z'), 
substitui todas as ocorrências da primeira letra na string pela segunda e retorna a string com as alterações efetuadas. 
Na saída padrão, para cada linha de entrada, execute o método desenvolvido nesta questão e mostre a string retornada como uma linha de saída.*/


bool isFim(char *string) {
    return strcmp(string, "FIM") == 0; // verifica se é o fim das entraadas
}

void altAl(){
    int entrada = 0;
    char string[1000];
    srand(4);

    int random_num1 = abs(rand()) % 26;
    char letter1 = 'a' + random_num1;
    int random_num2 = abs(rand()) % 26;
    char letter2 = 'a' + random_num2;

    scanf("%[^\n]%*c", string);

    if(isFim(string)){
        return;
    } else {
        for(int i=0; i < strlen(string); i++){
            if(string[i] == letter1){
                string[i] = letter2;
            }
        }
        printf("%s\n", string);
        altAl();
    }
}

int main(){
    altAl();
}