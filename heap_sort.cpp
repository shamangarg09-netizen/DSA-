
#include <iostream>
using namespace std;

// Heapify function
void heapify(int arr[], int n, int i) {
    int largest = i;       // Root node
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // Check if left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    heapSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
