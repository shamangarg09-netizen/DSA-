#include <iostream>
#include <vector>

using namespace std;

void sortBucket(vector<int>& bucket) {
	for (int i = 1; i < static_cast<int>(bucket.size()); i++) {
		int value = bucket[i];
		int j = i - 1;

		while (j >= 0 && bucket[j] > value) {
			bucket[j + 1] = bucket[j];
			j--;
		}

		bucket[j + 1] = value;
	}
}

void bucketSort(int arr[], int size) {
	if (size <= 1)
		return;

	int minimum = arr[0];
	int maximum = arr[0];

	for (int i = 1; i < size; i++) {
		if (arr[i] < minimum)
			minimum = arr[i];
		if (arr[i] > maximum)
			maximum = arr[i];
	}

	int bucketCount = maximum - minimum + 1;
	vector<vector<int>> buckets(bucketCount);

	for (int i = 0; i < size; i++)
		buckets[arr[i] - minimum].push_back(arr[i]);

	int index = 0;
	for (vector<int>& bucket : buckets) {
		sortBucket(bucket);

		for (int value : bucket) {
			arr[index] = value;
			index++;
		}
	}
}

void printArray(const int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << '\n';
}

int main() {
	int arr[] = {42, 32, 33, 52, 37, 47, 51};
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Before sorting:\n";
	printArray(arr, size);

	bucketSort(arr, size);

	cout << "After sorting:\n";
	printArray(arr, size);

	return 0;
}