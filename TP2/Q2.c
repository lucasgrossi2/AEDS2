#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int id;
    int gen;
    char name[80];
    char desc[500];
    char type1[20];
    char type2[20];
    char abls[10][80];
    double weight;
    double height;
    int capRate;
    bool isLeg;

}Pokemon;

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

int main(){

    Pokemon pokedex[801];

    FILE *file = fopen("pokemon.csv", "r");
    char line[500];
    fgets(line, sizeof(line), file);


    for(int i=0; i<801; i++){

       if (fgets(line, sizeof(line), file)){

            char *token = strtok(line, ",");
            pokedex[i].id = atoi(token);

            token = strtok(NULL, ",");
            pokedex[i].gen = atoi(token);

            token = strtok(NULL, ",");
            strcpy(pokedex[i].name, token);

            token = strtok(NULL, ",");
            strcpy(pokedex[i].desc, token);

            token = strtok(NULL, ",");
            strcpy(pokedex[i].type1, token);

            token = strtok(NULL, ",");
            strcpy(pokedex[i].type2, token); //existem casos em que essa string estará vazia e não será printada no final.

            //abls here

            token = strtok(NULL,)

            token = strtok(NULL, ",");
            pokedex[i].weight = atof(token);

            token = strtok(NULL, ",");
            pokedex[i].height = atof(token);

            token = strtok(NULL, ",");
            pokedex[i].capRate = atoi(token);

            token = strtok(NULL, ",");
            pokedex[i].isLeg = (strcmp(token, "true") == 0);
        }   
    }


    fclose(file);

    return 0;
}