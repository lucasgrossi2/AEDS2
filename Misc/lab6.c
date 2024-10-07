#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function that places the pivot element in its correct position
int partition(int arr[], int low, int high, int piv) {
    int pivot = arr[piv];
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap the pivot element with the element at i+1
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quicksort function
void quicksort(int arr[], int low, int high, int pivot) {
    if (low < high) {
        // Find the partition index
        int pi = partition(arr, low, high, pivot);

        // Recursively sort elements before and after partition
        quicksort(arr, low, pi - 1, pivot);
        quicksort(arr, pi + 1, high, pivot);
    }
}

void QuickSortFirstPivot(int arr[], int low, int high, int pivot){
    clock_t start_time = clock();
    quicksort(arr, low, high, pivot);
    clock_t end_time = clock();
    double time = ((double)(end_time - start_time) * 1000) / CLOCKS_PER_SEC;
    printf("tempo de execucao com primeiro pivo: %.6f\n", time);
}

void QuickSortLastPivot(int arr[], int low, int high, int pivot){
    clock_t start_time = clock();
    quicksort(arr, low, high, pivot);
    clock_t end_time = clock();
    double time = ((double)(end_time - start_time) * 1000) / CLOCKS_PER_SEC;
    printf("tempo de execucao com ultimo pivo: %.6f\n", time);
}

void QuickSortRandomPivot(int arr[], int low, int high, int pivot){
    clock_t start_time = clock();
    quicksort(arr, low, high, pivot);
    clock_t end_time = clock();
    double time = ((double)(end_time - start_time) * 1000) / CLOCKS_PER_SEC;
    printf("tempo de execucao com random pivo: %.6f\n", time);
}

void QuickSortMedianOfThree(int arr[], int low, int high, int pivot){
    clock_t start_time = clock();
    quicksort(arr, low, high, pivot);
    clock_t end_time = clock();
    double time = ((double)(end_time - start_time) * 1000) / CLOCKS_PER_SEC;
    printf("tempo de execucao com pivo mediana: %.6f\n", time);
}

// Main function to test the Quicksort algorithm
int main() {

    system("cls");

    int arr[10000];
    for(int i=0; i<10000; i++){
        arr[i] = rand()%10000;
    }

    srand(time(0));
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSortFirstPivot(arr, 0, n-1, 0);
    QuickSortLastPivot(arr, 0, n-1, n-1);
    QuickSortRandomPivot(arr, 0, n-1, rand()%100);
    int med;
    if((arr[0]<arr[n/2] && arr[0]>arr[n-1])||(arr[0]<arr[n-1] && arr[0]>arr[n/2])){
        med = arr[0];
    }else if((arr[n/2]<arr[0] && arr[n/2]>arr[n-1])||(arr[n/2]<arr[n-1] && arr[n/2]>arr[0])){
        med = arr[n/2];
    } else {
        med = arr[n-1];
    }
    QuickSortMedianOfThree(arr, 0, n-1, med);

    return 0;
}
