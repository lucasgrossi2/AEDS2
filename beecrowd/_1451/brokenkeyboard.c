#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkforbrackets(char* resultstring, char* old){
    for(int i = 0; i < strlen(resultstring); i++){
        if(resultstring[i] == '[' || resultstring[i] == ']'){
            strcpy(old, resultstring);
            return true;
        }
    }
    return false;
}

bool onlybrackets(char* final){
    int i = 0;
    while (final[i] != '\0'){
        if(final[i] != '[' && final[i] != ']'){
            return false;
        }
        i++;
    }
    return true;
}

void limparstrings(char* string, size_t size) {
    for(int i = 0; i < size; i++) {
        string[i] = '\0'; 
    }
}

int main(){
    char oldstring[10000];
    char newstring[10000];
    char beiju[10000];

    limparstrings(oldstring, sizeof(oldstring));
    limparstrings(newstring, sizeof(newstring));
    limparstrings(beiju, sizeof(beiju));

    while(fgets(oldstring, sizeof(oldstring), stdin) != NULL){
        oldstring[strcspn(oldstring, "\n")] = '\0';
        int done = 0;
        int inside = 0;
        if(!onlybrackets(oldstring)){
            do{
                for(int i = 0, j = 0, b = 0, brackbefore = 0; i < strlen(oldstring) && done == 0; i++){
                    if(oldstring[i] == '['){
                        inside = 1;
                    }else if(oldstring[i] == ']'){
                        inside = 0;
                    } else if(inside == 0){
                        newstring[j] = oldstring[i];
                        j++;
                    } else {
                        beiju[b] = oldstring[i];
                        b++;
                    }
                }
            }while(checkforbrackets(newstring, oldstring));
            strcat(beiju, newstring);
            printf("%s\n", beiju);

            limparstrings(oldstring, sizeof(oldstring));
            limparstrings(beiju, sizeof(beiju));
            limparstrings(newstring, sizeof(newstring));
        }


    }

    return 0;
}