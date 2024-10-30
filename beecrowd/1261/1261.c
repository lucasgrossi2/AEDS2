#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char palavra[17];
    int preco;
} definicao;

int main() {
    int nDefsDicionario;
    int nCargos;

    scanf("%d %d", &nDefsDicionario, &nCargos);
    getchar();

    definicao index[nDefsDicionario];

    for (int i = 0; i < nDefsDicionario; i++) {
        scanf("%16s %d", index[i].palavra, &index[i].preco);
    }

    char descricoesCargos[nCargos][1500];

    for (int i = 0; i < nCargos; i++) {
        char principal[1024];
        char atual[1024];

        fgets(principal, sizeof(principal), stdin);
        size_t length = strlen(principal);
        if (length > 0 && principal[length - 1] == '\n') {
            principal[length - 1] = '\0';
            length--;
        }

        strcpy(descricoesCargos[i], principal);
        strcat(descricoesCargos[i], " ");

        fgets(atual, sizeof(atual), stdin);
        while (strcmp(atual, ".\n") != 0 && strcmp(atual, ".") != 0) {
            size_t len = strlen(atual);
            if (len > 0 && atual[len - 1] == '\n') {
                atual[len - 1] = '\0';
                len--;
            }

            strcat(descricoesCargos[i], atual);
            strcat(descricoesCargos[i], " ");

            fgets(atual, sizeof(atual), stdin);
        }
    }

    return 0;
}
