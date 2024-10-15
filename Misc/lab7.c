#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}



int main(){
    int n;
    while(scanf("%d", &n)!= 0){
        int largada[n];
        int chegada[n];
        for(int m=0; m<n; m++){
            scanf("%d", &largada[m]);
        }
        for(int p=0; p<n; p++){
            scanf("%d", &chegada[p]);
        }
        printf("%d %d %d %d %d\n", largada[0], largada[1], largada[2], largada[3], largada[4]);

        printf("%d %d %d %d %d", chegada[0], chegada[1], chegada[2], chegada[3], chegada[4]);
    }



    return 0;
}