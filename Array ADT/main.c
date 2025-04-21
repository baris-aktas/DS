#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int *arr;
    int size;
} ADT;

ADT Create(int size) {
    ADT Array;
    Array.size = size;
    Array.arr = (int *) malloc(Array.size * sizeof(int));

    return Array;
}

ADT Fill(ADT Array) {
    printf("Enter the elements of the array:");
    for (int i = 0; i < Array.size; i++) {
        scanf("%d", &Array.arr[i]);
    }

    return Array;
}

void Display(ADT Array) {
    for (int i = 0; i < Array.size; i++) {
        printf("%d ", Array.arr[i]);
    }
    printf("\n");
}

void Append(ADT *Array, int element) {
    int *append = realloc(Array->arr, sizeof(int) * (Array->size + 1));

    if (append == NULL) {
        free(Array->arr);
        printf("Memory allocation error");
        exit(1);
    }

    Array->size = Array->size + 1;
    Array->arr = append;
    Array->arr[Array->size - 1] = element;
    append = NULL;
}

void Insert(ADT *Array, int index, int element) {
    if (index >= 0 && index <= Array->size) {
        Append(Array, 0);
        for (int i = Array->size; i > index; i--) {
            Array->arr[i] = Array->arr[i - 1];
        }
        Array->arr[index] = element;
    } else {
        printf("Index is out of range\n");
    }
}

void Delete(ADT *Array, int index) {
    if (index >= 0 && index < Array->size) {
        for (int i = index; i < Array->size - 1; i++) {
            Array->arr[i] = Array->arr[i + 1];
        }
        //Array->arr[Array->size - 1] = 0;
        int *remove = realloc(Array->arr, sizeof(int) * (Array->size - 1));
        if (remove == NULL) {
            free(Array->arr);
            printf("Memory allocation error");
            exit(1);
        }
        Array->size = Array->size - 1;
        Array->arr = remove;
        remove = NULL;
    } else {
        printf("Index is out of range\n");
    }
}

int Search(ADT Array, int key) {
    for (int i = 0; i < Array.size; i++) {
        if (Array.arr[i] == key) {
            printf("Element found at index %d\n", i);
            return i;
        }
    }
    printf("Element not found -1\n");
    return -1;
}

int BinarySearch(ADT Array, int key) {
    int low = 0, mid = 0, high = Array.size - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == Array.arr[mid]) {
            printf("Element found at index %d\n", mid);
            return mid;
        }
        if (key < Array.arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    printf("Element not found\n");
    return -1;
}


void Swap(ADT *Array, int x, int y) {
    int temp = Array->arr[x];
    Array->arr[x] = Array->arr[y];
    Array->arr[y] = temp;
}

void Sort(ADT *Array) {
    for (int i = 0; i < Array->size; i++) {
        for (int j = 0; j < Array->size; j++) {
            if (Array->arr[i] <= Array->arr[j]) {
                Swap(Array, i, j);
            }
        }
    }
}

int Get(ADT Array, int index) {
    if(index >=0 && index < Array.size) {
        return Array.arr[index];
    }
    printf("Index is out of range\n");
    return -1;

}

void Set(ADT *Array, int index, int element) {
    if(index >= 0 && index < Array->size) {
        Array->arr[index] = element;
    }
    printf("Index out of bound\n");

}

int Min(ADT Array) {
    int min = Array.arr[0];
    for (int i = 1; i < Array.size; i++) {
        if (Array.arr[i] < min) {
            min = Array.arr[i];
        }
    }

    printf("Minimum element is %d\n", min);
    return min;
}

int Max(ADT Array) {
    int max = Array.arr[0];
    for (int i = 1; i < Array.size; i++) {
        if (Array.arr[i] > max) {
            max = Array.arr[i];
        }
    }
    printf("Maximum element is %d\n", max);
    return max;

}

float Average(ADT Array) {
    float sum = 0;
    for (int i = 0; i < Array.size; i++) {
        sum += Array.arr[i];
    }
    printf("Sum of the elements is %f\n", sum);
    printf("Average of the array is %f\n", sum / Array.size);
    return sum / Array.size;
}

void Reverse(ADT *Array) {
    int i = 0, j = Array->size - 1;
    // int i,j;
    // for(i = 0, j = Array->size - 1; i < j ; i++ , j--)
    while (i < j) {
        Swap(Array, i, j);
        i++;
        j--;
    }
}

ADT Concatenate(ADT FirstArray, ADT SecondArray) {
    int size = FirstArray.size + SecondArray.size;
    ADT Array = Create(size);
    int j = 0;
    for (int i = 0; i < size; i++) {
        if(i < FirstArray.size) {
            Array.arr[i] = FirstArray.arr[i];
        }else {
            Array.arr[i] = SecondArray.arr[j];
            j++;
        }
    }

    return Array;
}



void Sorted(ADT Array) {
    int min = Array.arr[0];
    for (int i = 1; i < Array.size; i++) {
        if (min > Array.arr[i]) {
            printf("Array is not sorted.\n");
            exit(1);
        }
    }
    printf("Array is sorted.\n");
}

void Free(ADT Array) {
    free(Array.arr);
}

int main() {
    ADT Array = Create(5);
    Fill(Array);
    Display(Array);
    ADT Array2 = Create(7);
    Fill(Array2);
    Display(Array2);
    Append(&Array, 6);
    Display(Array);
    Insert(&Array, 2, 9);
    Search(Array, 9);
    Display(Array);
    Delete(&Array, 2);
    Search(Array, 9);
    Display(Array);
    Sort(&Array);
    Display(Array);
    Sorted(Array);
    BinarySearch(Array, 3);
    Reverse(&Array);
    Display(Array);
    Sorted(Array);
    ADT Array3 = Concatenate(Array, Array2);
    Display(Array3);
    Free(Array);
    Free(Array2);
    Free(Array3);

    return 0;
}
