//
// Created by Momchil Tsanov on 14.11.24.
//


#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> left_half(n1);
    std::vector<int> right_half(n2);

    for (int i = 0; i < n1; i++) {
        left_half[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        right_half[j] = arr[mid + 1 + j];
    }

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

        std::cout << "Razdelqm na dve: lqva polovina [" << left << ", " << mid << "] i dqsna polovina [" << mid + 1 << ", " << right << "]" << std::endl;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        std::cout << "Slivam: [" << left << ", " << mid << "] i [" << mid + 1 << ", " << right << "]" << std::endl;

        merge(arr, left, mid, right);
    }
}

void print_array(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr;
    //{64, 34, 25, 12, 22, 11, 90}
    for(int i = 0; i < 7; i++){
        arr.push_back(rand() % 100);
    }

    int n = arr.size();

    std::cout << "nachalen array: ";
    print_array(arr);

    merge_sort(arr, 0, n - 1);

    std::cout << "sortiran array: ";
    print_array(arr);

    return 0;
}