#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 10000
#define MIN_VAL 0
#define MAX_VAL 100000

void printArray(int arr[], int len);
int* generateRandomArray(int len);
// Declare your sorting function here
extern int* InsertionSort(int* array, int length);
extern int* BubbleSort(int* array, int length);

int main() {
    int n;
    srand((unsigned int)time(NULL));
    printf("Enter array length (1-%d): ", MAX_LEN);
    scanf("%d", &n);

    int* arr = generateRandomArray(n);
    printf("\nBefore sorting:\n");
    n <= 100 ? printArray(arr, n) : printf("(Omitted)\n");

    int choose;
    printf("Which sort do you like?\n");
    printf("1:Insertionsort;\n");
    printf("2:Bubblesort:\n");

    scanf("%d", &choose);
    switch(choose){
        case 1:
            InsertionSort(arr, n);
            break;
        case 2:
            BubbleSort(arr, n);
            break;
    }
    

    printf("\nAfter sorting:\n");
    n <= 100 ? printArray(arr, n) : printf("(Omitted)\n");

    free(arr);
    return 0;
}

int* generateRandomArray(int len) {
    int* arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
        arr[i] = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
    return arr;
}

void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    if (len % 10 != 0) printf("\n");
}