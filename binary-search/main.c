#include <stdio.h>


int binarySearch(int numbers[], int sizeOfArray,int searchedNumber);

int main() {
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8};
    int sizeOfArray = (sizeof (numbers) / sizeof (numbers[0])) - 1;
    int positionOfSearchedNumber = binarySearch(numbers, sizeOfArray, 1);

    if (positionOfSearchedNumber == -1)
        printf("Number not found");
    else
        printf("Element found at index %d", positionOfSearchedNumber);
    return 0;
}

int binarySearch(int numbers[], int sizeOfArray, int searchedNumber) {
    int low = 0;
    int high = sizeOfArray;

    while(low <= high) {
        int mid = (low + high) / 2;
        int guess = numbers[mid];

        if (guess == searchedNumber) return mid;

        if (guess > searchedNumber)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
