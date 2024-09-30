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
    char ntypes[40];
    char abls[200];
    double weight;
    double height;
    int capRate;
    char isLeg[40];
    int dia;
    int mes;
    int ano;

}Pokemon;

bool lerEntrada(const char *entrada){
    if(strcmp(entrada, "FIM") == 0){
        return false;
    } else {
        return true;
    }
}

int main(){

    Pokemon pokedex[801];

    FILE *file = fopen("pokemon.csv", "r");
    char line[500];
    fgets(line, sizeof(line), file);


    for(int i=0; i<801; i++){

       if (fgets(line, sizeof(line), file)){

            strcpy(pokedex[i].ntypes, "TWO");

            for(int j=0; j<strlen(line)-1; j++){
                if (line[j] == ',' && line[j+1] == ','){
                    strcpy(pokedex[i].ntypes, "ONE");
                }
            }

            char *token = strtok(line, ",");
            pokedex[i].id = atoi(token);

            token = strtok(NULL, ",");
            pokedex[i].gen = atoi(token);

            token = strtok(NULL, ",");
            strcpy(pokedex[i].name, token);

            token = strtok(NULL, ",");
            strcpy(pokedex[i].desc, token);


            //Tadpole Pokémon,water,,"['Swift Swim', 'Hydration', 'Water Absorb']"

            //Proud Pokémon,normal,flying,"['Big Pecks', 'Super Luck', 'Rivalry']"

            token = strtok(NULL, ",");
            strcpy(pokedex[i].type1, token);

            token = strtok(NULL, ",");
            if(strcmp(pokedex[i].ntypes, "TWO")==0){
                strcpy(pokedex[i].type2, token);
            } else {
                strcpy(pokedex[i].type2, "NULL");
            }

            token = strtok(NULL, "\"");
            //token = strtok(NULL, "\"");
            strcpy(pokedex[i].abls, token);

            token = strtok(NULL, ",");
            pokedex[i].weight = atof(token);

            token = strtok(NULL, ",");
            pokedex[i].height = atof(token);

            token = strtok(NULL, ",");
            pokedex[i].capRate = atoi(token);

            token = strtok(NULL, ",");
            int leg = atoi(token);
            if(leg == 0){
                strcpy(pokedex[i].isLeg, "false");
            } else {
                strcpy(pokedex[i].isLeg, "true");
            }


            char *ultVirgula = strrchr(line, ',');
            token = strtok(ultVirgula, "/");
            pokedex[i].dia = atoi(token);
            token = strtok(NULL, "/");
            pokedex[i].mes = atoi(token);
            token = strtok(NULL, "/");
            pokedex[i].ano = atoi(token);

        }   
    }

    char entrada[20];
    int index;
    int end = 0;

    do{
        scanf("%s", entrada);
        index = atoi(entrada)-1;
        if(lerEntrada(entrada)){
            if (strcmp(pokedex[index].ntypes, "TWO")){ //somente 1 tipo
            printf("[#%d -> %s: %s - ['%s'] - [%s - %.1lf - %.1lf - %d%% - %s - %d gen] - %d/%d/%d\n", pokedex[index].id, pokedex[index].name, pokedex[index].desc, pokedex[index].type1, pokedex[index].abls, pokedex[index].weight, pokedex[index].height, pokedex[index].capRate, pokedex[index].isLeg, pokedex[index].gen, pokedex[index].dia, pokedex[index].mes, pokedex[index].ano);
            } else { //2 tipos
                printf("[#%d -> %s: %s - ['%s', '%s'] - %s - %.1lf - %.1lf - %d%% - %s - %d gen] - %d/%d/%d\n", pokedex[index].id, pokedex[index].name, pokedex[index].desc, pokedex[index].type1, pokedex[index].type2, pokedex[index].abls, pokedex[index].weight, pokedex[index].height, pokedex[index].capRate, pokedex[index].isLeg, pokedex[index].gen, pokedex[index].dia, pokedex[index].mes, pokedex[index].ano);
            }
        } else {
            end++;
        }
    }while(end == 0);

    fclose(file);

    return 0;
}