//
//  main.cpp
//  MergeSort
//
//  Created by Momchil Tsanov on 5.11.24.
//

#include <iostream>

using namespace std;

void mergeSort(int arr[], int low, int high);

int main(int argc, const char * argv[]) {

    int arr[] {4,1,9,3,6,2,11,8,7,10};
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, 9);


    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

}

void merge(int arr[], int low, int mid, int high){


    int n1 = mid - low + 1;
    int n2 = high - mid;

    int a[n1], b[n2];
    for (int i = 0; i < n1; i++)
        a[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        b[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = low;

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

}



void mergeSort(int arr[], int low, int high) {


    if (low >= high){
        return;
    }

    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }


}
