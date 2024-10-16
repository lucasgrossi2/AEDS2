#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char cpf[12];
    int i;
    int dig;
    int numValidos = 0;
    srand(time(NULL));

    cpf[0] = '0';
    cpf[1] = '5';
    cpf[2] = '7';
    cpf[11] = '\0';

    for(int num = 0; num <= 999999; num++){

        sprintf(cpf + 3, "%06d", num);

        dig = ((((cpf[0] - '0') * 10) + ((cpf[1] - '0') * 9) + ((cpf[2] - '0') * 8) +
                ((cpf[3] - '0') * 7) + ((cpf[4] - '0') * 6) + ((cpf[5] - '0') * 5) +
                ((cpf[6] - '0') * 4) + ((cpf[7] - '0') * 3) + ((cpf[8] - '0') * 2)) % 11);
    
        if(dig == 0 || dig == 1) {
            cpf[9] = '0';
        } else {
            cpf[9] = (11 - dig) + '0'; 
        }


        dig = ((((cpf[0] - '0') * 11) + ((cpf[1] - '0') * 10) + ((cpf[2] - '0') * 9) +
                ((cpf[3] - '0') * 8) + ((cpf[4] - '0') * 7) + ((cpf[5] - '0') * 6) +
                ((cpf[6] - '0') * 5) + ((cpf[7] - '0') * 4) + ((cpf[8] - '0') * 3) +
                ((cpf[9] - '0') * 2)) % 11);
    
        if(dig == 0 || dig == 1) {
            cpf[10] = '0'; 
        } else {
            cpf[10] = (11 - dig) + '0'; 
        }

        if(cpf[9]=='5' && cpf[10]=='5'){
            for (i = 0; i < 11; i++) {
                printf("%c", cpf[i]); 
            }
            printf("\n");
            numValidos++;
        }
    }
    printf("============================\nNumero de CPFs validos: %d", numValidos);
    return 0;
}

