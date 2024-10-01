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

    char entrada[20];
    int index;
    int end = 0;

    do{
        scanf("%s", entrada);
        index = atoi(entrada)-1;
        if(lerEntrada(entrada)){
            if (pokedex[index].type2[0] == '\0'){ //somente 1 tipo
            printf("[#%d -> %s: %s - ['%s'] - %s - %.1lfkg - %.1lfm - %d%% - %s - %d gen] - %s", pokedex[index].id, pokedex[index].name, pokedex[index].desc, pokedex[index].type1, pokedex[index].abls, pokedex[index].weight, pokedex[index].height, pokedex[index].capRate, pokedex[index].isLeg, pokedex[index].gen, pokedex[index].data);
            } else { //2 tipos
                printf("[#%d -> %s: %s - ['%s', '%s'] - %s - %.1lfkg - %.1lfm - %d%% - %s - %d gen] - %s", pokedex[index].id, pokedex[index].name, pokedex[index].desc, pokedex[index].type1, pokedex[index].type2, pokedex[index].abls, pokedex[index].weight, pokedex[index].height, pokedex[index].capRate, pokedex[index].isLeg, pokedex[index].gen, pokedex[index].data);
            }
        } else {
            end++;
        }
    }while(end == 0);

    fclose(file);
    return 0;
}