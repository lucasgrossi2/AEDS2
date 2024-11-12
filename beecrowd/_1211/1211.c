#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void scanforN(int *n, int *eof){
    if(scanf("%d", n)==EOF){;
        (*eof)++;
    }
}



int main(){

    int eof = 0;
    int n = 1;

    scanforN(&n, &eof);
    while(eof == 0){
        char **lista = malloc((n + 1) * sizeof(char *)); 
        for(int i = 0; i < n; i++){
            lista[i] = malloc(200 * sizeof(char));
        }
        for(int i = 0; i < n; i++){
            scanf("%s", lista[i]);
        }
        int salvos = 0;
        int size = strlen(lista[0]);
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < size && j >= 0; j++){
                if(lista[i][j] == lista[i+1][j]){
                    salvos++;
                } else {
                    j = -5;
                }
            }
        }
        printf("%d", salvos);
        scanforN(&n, &eof);
        if(eof == 0){
            printf("\n");
        }
    }
    
    return 0;
}