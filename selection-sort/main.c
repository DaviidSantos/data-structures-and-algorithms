#include <stdio.h>
#include <stdlib.h>

int* selectionSort(int *pArray, int length);
int smallestElement(int *pArray, int length);
void removeItem(int *pArray, int index, int length);

int main() {
    int numbers[10] = { 3, 5, 4, 6, 7, 8, 10, 1, 9, 2};

    int length = (sizeof (numbers) / sizeof (numbers[0]));

    int* sortedNumbers = selectionSort(numbers, length);

    printf("{ ");
    for (int i = 0; i < length; ++i) {
        if(i < length - 1) {
            printf("%d, ", sortedNumbers[i]);
        } else {
            printf("%d", sortedNumbers[i]);
        }
    }
    printf(" }");

    free(sortedNumbers);
    return 0;
}

int* selectionSort(int *pArray, int length) {
    int* sortedNumbers = (int*) malloc(length * sizeof(int));

    for (int i = 0; i < length; ++i) {
        int smallest = smallestElement(pArray, length - i);
        sortedNumbers[i] = smallest;
    }

    return sortedNumbers;
}

int smallestElement(int *pArray, int length) {
    int smallest = pArray[0];
    int index = 0;

    for (int i = 0; i < length; ++i) {
        if (pArray[i] < smallest) {
            smallest = pArray[i];
            index = i;
        }

    }

    removeItem(pArray, index, length);

    return smallest;
}

void removeItem(int *pArray, int index, int length) {
    for (int i = index; i < length; ++i) {
        pArray[i] = pArray[i + 1];
    }
}
