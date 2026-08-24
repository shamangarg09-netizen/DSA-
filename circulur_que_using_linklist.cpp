#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* rear = nullptr;

void enqueue(int element) {
	Node* newNode = new Node{element, nullptr};

	if (rear == nullptr) {
		rear = newNode;
		rear->next = rear;
	} else {
		newNode->next = rear->next;
		rear->next = newNode;
		rear = newNode;
	}
}

bool dequeue(int& element) {
	if (rear == nullptr) {
		return false;
	}

	Node* front = rear->next;
	element = front->data;

	if (front == rear) {
		rear = nullptr;
	} else {
		rear->next = front->next;
	}

	delete front;
	return true;
}

void display() {
	if (rear == nullptr) {
		cout << "Queue is empty.\n";
		return;
	}

	Node* current = rear->next;
	cout << "Queue: ";

	do {
		cout << current->data << ' ';
		current = current->next;
	} while (current != rear->next);

	cout << '\n';
}

int main() {
	int choice;

	do {
		cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			int element;
			cout << "Enter the element: ";
			cin >> element;
			enqueue(element);
		} else if (choice == 2) {
			int element;
			if (dequeue(element)) {
				cout << "Dequeued element: " << element << '\n';
			} else {
				cout << "Queue is empty.\n";
			}
		} else if (choice == 3) {
			display();
		} else if (choice != 4) {
			cout << "Invalid choice.\n";
		}
	} while (choice != 4);

	return 0;
}