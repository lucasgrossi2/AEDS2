/* Papai Noel está nos preparativos finais para a entrega dos presentes para as crianças do mundo todo 
pois o natal está chegando mais uma vez. Olhando suas novas listas de crianças que irão ganhar 
presentes neste ano ele percebeu que o duende estagiário (que havia ficado responsável por fazer as 
listas) não havia colocado os nomes em ordem alfabética.

Como o Papai Noel é um homem muito organizado ele deseja que cada lista de crianças possua, no seu 
final, o total de crianças que foram bem comportadas neste ano e um total das que não foram. 
Assim ele pode comparar a quantidade de crianças que se comportam este ano com as dos anos anteriores.

Para ajudar o bom velhinho, seu dever é criar um programa que leia todos os nomes da lista e imprima 
os mesmos nomes em ordem alfabética. No final da lista, você deve imprimir o total de crianças que 
foram e não foram comportadas neste ano.

Entrada
A entrada é composta por vários nomes. O primeiro valor N (0 ≤ N ≤ 100), indica quantos nomes tem na 
lista. As N linhas seguintes, contem um caracter especial correspondente ao comportamento da criança 
(+ indica que a criança foi bem comportada, - indica que a criança não foi bem comportada). 
Após o caracter especial, segue o nome da criança com no máximo 20 caracteres.

Saída
Para cada lista de crianças, você deve imprimir os nomes em ordem alfabética. 
Após imprimir os nomes das crianças, você deve mostrar o total de crianças que se comportaram bem 
ou mal durante o ano. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int total;
    int positivos = 0;
    int negativos = 0;
    char sinais[150][150];
    char pos[] = "+";
    scanf("%d", &total);
    char **nomesCru = malloc((total + 1) * sizeof(char*));

    for (int i = 0; i < total; i++) {
        char temp[100];
        scanf("%s %s", sinais[i], temp);
        nomesCru[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(nomesCru[i], temp);
    }

    for (int j = 0; j < total; j++) {
        if (strcmp(sinais[j], pos) == 0) {
            positivos++;
        } else {
            negativos++;
        }
    }

    for (int k = 0; k < total - 1; k++) {
        int index = k;
        for (int m = k + 1; m < total; m++) {
            if (strcmp(nomesCru[index], nomesCru[m]) > 0) {
                index = m; 
            }
        }

        if (index != k) {
            char *tempor = nomesCru[index]; 

            for (int p = index; p > k; p--) {
                nomesCru[p] = nomesCru[p - 1];
            }

            nomesCru[k] = tempor;
        }
    }

    for (int b = 0; b < total; b++) {
        printf("\n%s", nomesCru[b]);
    }

    printf("\nSe comportaram: %d | Nao se comportaram: %d", positivos, negativos);

    for (int b = 0; b < total; b++) {
        free(nomesCru[b]);
    }

    return 0;
}

