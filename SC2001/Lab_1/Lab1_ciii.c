#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000000

void insertionSort(int arr[], int low, int high, int *count) {
    int i, j, key;
    for (i = low + 1; i <= high; i++) {
        key = arr[i]; // number to insert to the sorted array
        j = i - 1;

        // check elements from the right of sorted array whether it's larger than key,
        // shift element to the right by one slot if larger
        while (j >= low && arr[j] > key) {
            (*count)++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // insert number into the right slot of the sorted array
        arr[j + 1] = key;
    }
}

void merge(int* arr, int low, int mid, int high, int *count) {
    int i, j, k;
    int n1 = mid - low + 1; // size of Left Array
    int n2 = high - mid; // size of Right Array (high - mid + 1 - 1) = high - mid

    int* L = (int*)malloc(sizeof(int) * n1); // initialise left array
    int* R = (int*)malloc(sizeof(int) * n2); // initialise right array

    // copy over items from left sorted array
    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];

    // copy over items from right sorted array
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        (*count)++;
        // compare first item from left array with first item from right array, copy smaller item over
        // repeats until either left or right array is empty
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining items from left array
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy remaining items from right array
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void hybridSort(int* arr, int low, int high, int *count, int SORT_THRESHOLD) {
    // use insertion sort if array is smaller than SORT_THRESHOLD
    if (high - low <= SORT_THRESHOLD) {
        insertionSort(arr, low, high, count);
    // use merge sort if array is bigger than SORT_THRESHOLD
    } else if (low < high) {
        int mid = (low + high) / 2;
        hybridSort(arr, low, mid, count, SORT_THRESHOLD);
        hybridSort(arr, mid + 1, high, count, SORT_THRESHOLD);
        merge(arr, low, mid, high, count);
    }
}

int main() {
    int n, i, j;
    int count = 0;
    FILE* fpt;
    fpt = fopen("data_ciii.csv", "w");
    fprintf(fpt,"n, S, comparisons\n");

    for (int SORT_THRESHOLD = 2; SORT_THRESHOLD <= 15; SORT_THRESHOLD++) {
        j = 0;
        for (n = 1000; n <= MAX; j++) {
            int* arr = (int*)malloc(sizeof(int) * n);
            srand(time(NULL));
            for (i = 0; i < n; i++) {
                arr[i] = rand() % n + 1;
            }
            count = 0;
            hybridSort(arr, 0, n - 1, &count, SORT_THRESHOLD);
            printf("For S = %d, n = %d, number of key comparisons = %d\n", SORT_THRESHOLD, n, count);
            fprintf(fpt, "%d, %d, %d\n", n, SORT_THRESHOLD, count);
            free(arr);
            n *= (j % 2 == 0 ? 5 : 2);
        }
    }
    fclose(fpt);
    return 0;
}
