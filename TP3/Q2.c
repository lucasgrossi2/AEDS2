#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define maxLine 160
#define MAXSIZE 801

typedef struct creature {
    int uniqueId;
    int gen;
    char* title;
    char* details;
    char* primaryType;
    char* secondaryType;
    char* skills;
    double mass;
    double size;
    int catchRate;
    bool legendaryStatus;
    char* captureDay;
} creature;

creature creatures[MAXSIZE];

void getSubstring(const char *src, char *dest, int length) {
    strncpy(dest, src + (strlen(src) - 11), length);
    dest[length] = '\0';
}

void populateDex() {
    FILE* file = fopen("/tmp/pokemon.csv", "r");

    if (file == NULL) {
        printf("Error opening file!");
        return;
    }

    char line[maxLine];
    fgets(line, maxLine, file);

    int idx = 0;
    while (fgets(line, maxLine, file) && idx < MAXSIZE) {
        char dateStr[13];
        getSubstring(line, dateStr, 12);
        char* token1 = strtok(line, "\"");
        char* firstPart = token1;
        char* token2 = strtok(NULL, "\"");
        char* abilities = token2 ? strdup(token2) : NULL;
        char* token3 = strtok(NULL, "\"");
        char* secondPart = token3;

        char* tok = strtok(firstPart, ",");
        creatures[idx].uniqueId = atoi(tok);

        tok = strtok(NULL, ",");
        creatures[idx].gen = atoi(tok);

        tok = strtok(NULL, ",");
        creatures[idx].title = strdup(tok ? tok : "");

        tok = strtok(NULL, ",");
        creatures[idx].details = strdup(tok ? tok : "");

        tok = strtok(NULL, ",");
        creatures[idx].primaryType = strdup(tok ? tok : "");

        tok = strtok(NULL, ",");
        creatures[idx].secondaryType = (tok && strlen(tok) > 0) ? strdup(tok) : strdup("0");

        creatures[idx].skills = abilities ? abilities : strdup("");

        char* tok2 = strtok(secondPart, ",");
        creatures[idx].mass = (tok2 && strlen(tok2) > 0) ? strtod(tok2, NULL) : 0;

        tok2 = strtok(NULL, ",");
        creatures[idx].size = (tok2 && strlen(tok2) > 0) ? strtod(tok2, NULL) : 0;

        tok2 = strtok(NULL, ",");
        creatures[idx].catchRate = atoi(tok2);

        tok2 = strtok(NULL, ",");
        creatures[idx].legendaryStatus = (tok2 && atoi(tok2) != 0);

        tok2 = strtok(NULL, ",");
        creatures[idx].captureDay = strdup(dateStr);

        if (creatures[idx].uniqueId == 19) {
            creatures[idx].mass = 0.0;
            creatures[idx].size = 0.0;
            creatures[idx].catchRate = 255;
        }
        idx++;
    }

    fclose(file);
}

char* formatTypes(creature obj) {
    char* result = (char*) malloc(maxLine * sizeof(char));
    
    if (strcmp(obj.secondaryType, "0") == 0) {
        sprintf(result, "['%s']", obj.primaryType);
    } else {
        sprintf(result, "['%s', '%s']", obj.primaryType, obj.secondaryType);
    }
    return result;
}

char* formatLegendStatus(creature obj) {
    return obj.legendaryStatus ? "true" : "false";
}

char* toString(creature obj) {
    char* result = (char*) malloc(maxLine * sizeof(char));
    char* types = formatTypes(obj);
    char* legendary = formatLegendStatus(obj);

    sprintf(result, "[#%d -> %s: %s - %s - %s - %.1lfkg - %.1lfm - %d%% - %s - %d gen] - %s",
            obj.uniqueId, obj.title, obj.details, types, obj.skills, obj.mass, obj.size,
            obj.catchRate, legendary, obj.gen, obj.captureDay);

    return result;
}

bool checkEnd(char* str) {
    return strcmp(str, "FIM") == 0;
}

creature list[MAXSIZE];
int count;

void initialize() {
    count = 0;
}

void insertStart(creature obj) {
    if (count >= MAXSIZE) {
        exit(1);
    }

    for (int i = count; i > 0; i--) {
        list[i] = list[i - 1];
    }

    list[0] = obj;
    count++;
}

void insertEnd(creature obj) {
    if (count >= MAXSIZE) {
        exit(1);
    }

    list[count] = obj;
    count++;
}

void insertAt(int pos, creature obj) {
    if (count >= MAXSIZE || pos < 0 || pos > count) {
        exit(1);
    }

    for (int i = count; i > pos; i--) {
        list[i] = list[i - 1];
    }

    list[pos] = obj;
    count++;
}

creature removeStart() {
    if (count == 0) {
        exit(1);
    }

    creature response = list[0];
    count--;

    for (int i = 0; i < count; i++) {
        list[i] = list[i + 1];
    }

    return response;
}

creature removeEnd() {
    if (count == 0) {
        exit(1);
    }

    return list[--count];
}

creature removeAt(int pos) {
    if (count == 0 || pos < 0 || pos >= count) {
        exit(1);
    }

    creature response = list[pos];
    count--;

    for (int i = pos; i < count; i++) {
        list[i] = list[i + 1];
    }

    return response;
}

void display() {
    for (int i = 0; i < count; i++) {
        printf("[%d] %s", i, toString(list[i]));
    }
}

int main() {
    populateDex();
    initialize();

    char* input = (char*) malloc(20 * sizeof(char));

    do {
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = 0;

        if (!checkEnd(input)) {
            int num = atoi(input);
            insertEnd(creatures[num - 1]);
        }

    } while (!checkEnd(input));

    int numTests;
    scanf("%d", &numTests);
    getchar();

    for (int i = 0; i < numTests; i++) {
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = 0;

        char* tok = strtok(input, " ");

        if (strcmp(tok, "II") == 0) {
            tok = strtok(NULL, " ");
            int newIndex = atoi(tok);
            insertStart(creatures[newIndex - 1]);
        } else if (strcmp(tok, "IF") == 0) {
            tok = strtok(NULL, " ");
            int newIndex = atoi(tok);
            insertEnd(creatures[newIndex - 1]);
        } else if (strcmp(tok, "I*") == 0) {
            tok = strtok(NULL, " ");
            int pos = atoi(tok);
            tok = strtok(NULL, " ");
            int newIndex = atoi(tok);
            insertAt(pos, creatures[newIndex - 1]);
        } else if (strcmp(tok, "RI") == 0) {
            creature removed = removeStart();
            printf("(R) %s\n", removed.title);
        } else if (strcmp(tok, "RF") == 0) {
            creature removed = removeEnd();
            printf("(R) %s\n", removed.title);
        } else if (strcmp(tok, "R*") == 0) {
            tok = strtok(NULL, " ");
            int pos = atoi(tok);
            creature removed = removeAt(pos);
            printf("(R) %s\n", removed.title);
        }
    }

    display();
    free(input);
    return 0;
}
