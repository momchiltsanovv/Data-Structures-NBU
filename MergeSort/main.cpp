#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void merge(long arr[], long low, long mid, long high);
void mergeSort(long arr[], long low, long high);
void fillRandomArray(long arr[], int size);

void fillRandomArray(long arr[], int size) {
    srand(static_cast<unsigned long>(time(0)));
    for (long i = 0; i < size; i++) {
        arr[i] = rand() % 30000;
    }
}

int main(int argc, const char* argv[]) {
    for (long size = 10000; size <= 100000; size += 10000) {
        long* arr = new long[size];
        fillRandomArray(arr, size);

        clock_t c0 = clock();
        mergeSort(arr, 0, size - 1); // Sort the array
        clock_t c1 = clock();

        cout << "Time taken to sort " << size << " elements: "
             << static_cast<float>(c1 - c0) / CLOCKS_PER_SEC << " seconds" << endl;

        delete[] arr;
    }
}

void merge(long arr[], long low, long mid, long high) {
    long n1 = mid - low + 1;
    long n2 = high - mid;

    long* a = new long[n1];
    long* b = new long[n2];

    for (long i = 0; i < n1; i++) {
        a[i] = arr[low + i];
    }

    for (long j = 0; j < n2; j++) {
        b[j] = arr[mid + 1 + j];
    }

    long i = 0, j = 0;
    long k = low;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }

    delete[] a; // Free allocated memory
    delete[] b; // Free allocated memory
}

void mergeSort(long arr[], long low, long high) {
    if (low < high) {
        long mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
