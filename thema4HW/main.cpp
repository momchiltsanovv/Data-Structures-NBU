#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void mergeWithCheck(const int arr1[], int size1, const int arr2[], int size2, int merged[]);
void mergeWithoutCheck(const int arr1[], int size1, const int arr2[], int size2, int merged[]);
void printArray(const string& name, int arr[], int size);

int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int merged[size1 + size2];

    clock_t startCheck = clock();
    mergeWithCheck(arr1, size1, arr2, size2, merged);
    clock_t endCheck = clock();
    double timeWithCheck = static_cast<float>(endCheck - startCheck) / CLOCKS_PER_SEC;

    printArray("Array 1", arr1, size1);
    printArray("Array 2", arr2, size2);
    printArray("Merged Array (With Check)", merged, size1 + size2);

    cout << fixed << setprecision(10);
    cout << "Time taken with intermediate check: " << timeWithCheck << " seconds" << endl;

    int merged2[size1 + size2];
    clock_t startNoCheck = clock();
    mergeWithoutCheck(arr1, size1, arr2, size2, merged2);
    clock_t endNoCheck = clock();
    double timeWithoutCheck = static_cast<float>(endNoCheck - startNoCheck) / CLOCKS_PER_SEC;

    printArray("Merged Array (Without Check)", merged2, size1 + size2);

    cout << "Time taken without intermediate check: " << timeWithoutCheck << " seconds" << endl;

    return 0;
}


void mergeWithCheck(const int arr1[], int size1, const int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

void mergeWithoutCheck(const int arr1[], int size1, const int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    for (; i < size1; i++) {
        merged[k++] = arr1[i];
    }

    for (; j < size2; j++) {
        merged[k++] = arr2[j];
    }
}

void printArray(const string& name, int arr[], int size) {
    cout << name << ": ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}