// 백준 1026 보물.cpp

#include <iostream>
#define SWAP(x,y,temp) ((temp) = (x), (x) = (y), (y) = (temp))

int *qsort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int idx = low - 1;
        int temp = 0;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                idx++;
                SWAP(arr[idx], arr[j], temp);
            }
        }
        SWAP(arr[idx + 1], arr[high], temp);

        int pivot_idx = idx + 1;

        qsort(arr, low, pivot_idx - 1);
        qsort(arr, pivot_idx + 1, high);
    }
    return arr;
}

int* reverse_qsort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int idx = low - 1;
        int temp = 0;

        for (int j = low; j < high; j++) {
            if (arr[j] >= pivot) {
                idx++;
                SWAP(arr[idx], arr[j], temp);
            }
        }
        SWAP(arr[idx + 1], arr[high], temp);

        int pivot_idx = idx + 1;

        reverse_qsort(arr, low, pivot_idx - 1);
        reverse_qsort(arr, pivot_idx + 1, high);
    }
    return arr;
}

int main(){
    int size;
    int sum = 0;
    std::cin >> size;

    int* A = new int[size];
    int* B = new int[size];

    for (int i = 0; i < size; i++) std::cin >> A[i];
    for (int i = 0; i < size; i++) std::cin >> B[i];

    A = qsort(A, 0, size-1);
    B = reverse_qsort(B, 0, size - 1);

    for (int i = 0; i < size; i++) sum += A[i] * B[i];
    std::cout << sum;
    delete[] A;
    delete[] B;
}

