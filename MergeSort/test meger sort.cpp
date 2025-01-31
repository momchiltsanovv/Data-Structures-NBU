#include <iostream>
//
// Created by Momchil Tsanov on 31.01.25.
//
void merge(long arr[], const long low, const long mid, const long high) {
    const long n1 = mid - low + 1;
    const long n2 = high - mid;

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
        }
        else {
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

void mergeSort(long arr[], const long low, const long high) {
    if (low < high) {
        const long mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    long arr[] = {23, 1, 7, 9, 12, 34, 69, 2, 7, 9};
    for (const long i : arr) {
        std::cout << i << " ";
    }
    mergeSort(arr, 0, 10);
    std::cout << std::endl;
    for (const long i : arr) {
        std::cout << i << " ";
    }
}
