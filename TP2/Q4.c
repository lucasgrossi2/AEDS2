#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int id;
    int gen;
    char name[160];
    char desc[1000];
    char type1[40];
    char type2[40];
    char abls[200];
    double weight;
    double height;
    int capRate;
    char isLeg[40];
    char data[20];

}Pokemon;

bool lerEntrada(const char *entrada){
    if(strcmp(entrada, "FIM") == 0){
        return false;
    } else {
        return true;
    }
}

char *acharChar(const char *str, char character, int n){
    int reps = 0;
    while(*str != '\0'){
        if(*str == character){
            reps++;
            if(reps == n){
                return (char*)str;
            }
        }
        str++;
    }
    return NULL;
}

char *entreVirgs(const char *str, int n) {
    if (n == 0) {
        char *end = acharChar(str, ',', 1);
        size_t length = end - str;
        char *result = (char *)malloc(length + 1);
        strncpy(result, str, length);
        result[length] = '\0'; 
        return result;
    }

    char *start = acharChar(str, ',', n);
    char *end = acharChar(start + 1, ',', 1);
    if(end == NULL){
        end = (char*)(str + strlen(str));
    }
    size_t length = end - (start + 1);
    char *result = (char *)malloc(length + 1);
    strncpy(result, start + 1, length);
    result[length] = '\0';
    return result;
}

char *separarAbls(const char *str) {

    char *start = strchr(str, '\"');
    char *end = strchr(start + 1, '\"');
    int length = end - start - 1;

    char *substring = (char *)malloc(length + 1);

    strncpy(substring, start + 1, length);
    substring[length] = '\0';

    return substring;
}

char *removerAbls(const char *str) {

    char *start = strchr(str, '\"');
    char *end = strchr(start + 1, '\"');

    int before_len = start - str;  
    int after_len = strlen(end + 1); 

    char *new_str = (char *)malloc(before_len + after_len + 1);

    strncpy(new_str, str, before_len);
    strcpy(new_str + before_len, end + 1);

    return new_str;
}

int main(){

    system("cls");

    Pokemon pokedex[801];

    FILE *file = fopen("/tmp/pokemon.csv", "r");
    char line[500];
    fgets(line, sizeof(line), file);

    for(int i=0; i<801; i++){
        if(fgets(line, sizeof(line), file)){
            strcpy(pokedex[i].abls, separarAbls(line));
            char *readyString = removerAbls(line);

            pokedex[i].id = atoi(entreVirgs(readyString, 0));
            pokedex[i].gen = atoi(entreVirgs(readyString, 1));
            strcpy(pokedex[i].name, entreVirgs(readyString, 2));
            strcpy(pokedex[i].desc, entreVirgs(readyString, 3));
            strcpy(pokedex[i].type1, entreVirgs(readyString, 4));
            strcpy(pokedex[i].type2, entreVirgs(readyString, 5));
            pokedex[i].weight = atof(entreVirgs(readyString, 7));
            pokedex[i].height = atof(entreVirgs(readyString, 8));
            pokedex[i].capRate = atoi(entreVirgs(readyString, 9));
            if(atoi(entreVirgs(readyString, 10)) == 1){
                strcpy(pokedex[i].isLeg, "true");
            } else {
                strcpy(pokedex[i].isLeg, "false");
            }
            strcpy(pokedex[i].data, entreVirgs(readyString, 11));
        }    



    }

    char entrada[40];
    int index = 0;
    int end = 0;
    int listaIDs[801];
    int listaNomes[801];
    int sizelistaNomes = 0;
    int sizelistaIDs = 0;

    do{
        scanf("%s", entrada);
        if(lerEntrada(entrada)){
        listaIDs[index]=atoi(entrada);
        sizelistaIDs++;    
        index++;
        } else {
            end++;
        }
    }while(end == 0);

    end = 0;

    do{
        scanf("%s", entrada);
        if(lerEntrada(entrada)){
            for(index = 0; index < 801; index++){
                if(strcmp(entrada, pokedex[index].name)){
                    listaNomes[index] = pokedex[atoi(entrada)].id; //colocar os nomes na lista de nomes ja convertidos para IDs
                    sizelistaNomes++;
                }
            }
        } else {
            end++;
        }
    }while(end == 0);

    /*for(int i=0; i < sizelistaNomes; i++){
        int igual = 0;
        for(int j=0; j < sizelistaIDs; j++){
            if(listaIDs[j] == listaNomes[i]){
                printf("SIM\n");
                igual++;
                break;
            }
        }
        if(igual==0){
            printf("NAO\n");
        }
    }*/

    printf("%d\n", sizelistaIDs);
    printf("%d, %d, %d\n", listaNomes[0], listaNomes[1], listaNomes[2]);





    fclose(file);
    return 0;
}