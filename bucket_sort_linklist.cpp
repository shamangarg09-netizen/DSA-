#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) {}
};

void insert(Node*& head, int value) {
	Node* newNode = new Node(value);

	if (head == nullptr) {
		head = newNode;
		return;
	}

	Node* current = head;
	while (current->next != nullptr)
		current = current->next;

	current->next = newNode;
}

void insertSorted(Node*& bucket, Node* node) {
	if (bucket == nullptr || node->data < bucket->data) {
		node->next = bucket;
		bucket = node;
		return;
	}

	Node* current = bucket;
	while (current->next != nullptr && current->next->data <= node->data)
		current = current->next;

	node->next = current->next;
	current->next = node;
}

Node* bucketSort(Node* head) {
	if (head == nullptr || head->next == nullptr)
		return head;

	int minimum = head->data;
	int maximum = head->data;
	int size = 0;

	for (Node* current = head; current != nullptr; current = current->next) {
		if (current->data < minimum)
			minimum = current->data;
		if (current->data > maximum)
			maximum = current->data;
		size++;
	}

	long long range = static_cast<long long>(maximum) - minimum + 1;
	vector<Node*> buckets(size, nullptr);

	while (head != nullptr) {
		Node* node = head;
		head = head->next;
		node->next = nullptr;

		long long offset = static_cast<long long>(node->data) - minimum;
		int bucketIndex = static_cast<int>((offset * size) / range);
		if (bucketIndex == size)
			bucketIndex--;

		insertSorted(buckets[bucketIndex], node);
	}