#include <stdio.h>
#include <stdlib.h>


int *CreateArray(int size) {
    int *arr = (int *) malloc(size * sizeof(int));
    return arr;
}

int *FillArray(int *arr, int size) {
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    return arr;
}

void PrintArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int Max(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int Min(int *arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
}

void MemoryCopyArray(int *source, int *destination, int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void FreeArray(int *arr) {
    free(arr);
}


int main(void) {
    printf("Enter the size of an array\n");
    int size;
    scanf("%d", &size);

    int *A = CreateArray(size);

    FillArray(A, size);

    PrintArray(A, size);

    printf("Max value is: %d\n", Max(A, size));
    printf("Min value is: %d\n", Min(A, size));

    printf("Enter the new size for the new array\n");
    scanf("%d", &size);

    int *B = CreateArray(size);

    MemoryCopyArray(A, B, size);

    PrintArray(B, size);

    FreeArray(A);
    FreeArray(B);

    return 0;
}
