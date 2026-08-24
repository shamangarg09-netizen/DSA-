#include <iostream>
#include <algorithm>

using namespace std;

void Qsort(int arr[], int low, int high) {

    if (low >= high)
        return;

    int i = low + 1;
    int j = high;
    int pivot = arr[low];

    while (i <= j) {

        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        while (j >= low && arr[j] >= pivot) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);

    Qsort(arr, low, j - 1);
    Qsort(arr, j + 1, high);
}

int main() {

    int arr[8] = {7, 2, 5, 3, 8, 18, 3, 10};

    Qsort(arr, 0, 7);

    for (int i = 0; i < 8; i++) {
        cout << arr[i] << ' ';
    }
}