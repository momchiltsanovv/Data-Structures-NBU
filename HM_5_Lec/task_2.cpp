//
// Created by Momchil Tsanov on 14.11.24.
//
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> left_half(n1);
    std::vector<int> right_half(n2);

    for (int i = 0; i < n1; i++)
        left_half[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        right_half[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (left_half[i] <= right_half[j]) {
            arr[k] = left_half[i];
            i++;
        } else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_half[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void generate_random_array(std::vector<int>& arr, int size) {
    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % 10000);
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    const int MAX_SIZE = 10000;
    const int STEP = 1000;
    std::vector<int> sizes;

    std::cout << "Size\tMerge Sort (ms)\tQuick Sort (ms)" << std::endl;

    for (int size = STEP; size <= MAX_SIZE; size += STEP) {
        std::vector<int> arr;

        generate_random_array(arr, size);
        clock_t c0 = clock();
        quick_sort(arr, 0, arr.size() - 1);
        clock_t c1 = clock();


        arr.clear();
        generate_random_array(arr, size);
        clock_t c2 = clock();
        merge_sort(arr, 0, arr.size() - 1);
        clock_t c3 = clock();




        std::cout << size << "\t" << static_cast<float>(c3 - c2) / CLOCKS_PER_SEC << "\t\t" << static_cast<float>(c1 - c0) / CLOCKS_PER_SEC << std::endl;
    }

    return 0;
}
