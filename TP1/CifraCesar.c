#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*O Imperador Júlio César foi um dos principais nomes do Império Romano. Entre suas contribuições, temos um algoritmo de criptografia chamado ``Ciframento de César''. 
Segundo os historiadores, César utilizava esse algoritmo para criptografar as mensagens que enviava aos seus generais durante as batalhas. 
A ideia básica é um simples deslocamento de caracteres. Assim, por exemplo, se a chave utilizada para criptografar as mensagens for 3, 
todas as ocorrências do caractere 'a' são substituídas pelo caractere 'd', as do 'b' por 'e', e assim sucessivamente.

Crie um método iterativo que recebe uma string como parâmetro e retorna outra contendo a entrada de forma cifrada. Neste exercício, suponha a chave de ciframento três. 
Na saída padrão, para cada linha de entrada, escreva uma linha com a mensagem criptografada.*/


bool isFim(char *palavra) {
    return strcmp(palavra, "FIM") == 0; // se for FIM, retorna 1, se não for FIM, retorna 0
}

int main(){
    char strings[1000][1000];
    int entrada = 0;
    do {
        scanf("%[^\n]%*c", strings[entrada]);
    } while (isFim(strings[entrada++])==0);
    entrada--;

    for(int i=0; i < entrada; i++){
        for(int j=0; j < strlen(strings[i]); j++){
        int ASCII = (int)strings[i][j];
        strings[i][j] = (char)(ASCII+3);
        }
        printf("%s\n", strings[i]);
    }
} 