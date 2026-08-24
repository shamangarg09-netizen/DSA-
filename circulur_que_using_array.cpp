#include <iostream>

using namespace std;

const int capacity = 10;
int arr[capacity];
int frontIndex = 0;
int rearIndex = 0;
int queueSize = 0;

bool enqueue(int element) {
    if (queueSize == capacity) {
        return false;
    }

    arr[rearIndex] = element;
    rearIndex = (rearIndex + 1) % capacity;
    queueSize++;
    return true;
}

bool deque(int& element) {
    if (queueSize == 0) {
        return false;
    }

    element = arr[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    queueSize--;
    return true;
}

void display() {
    if (queueSize == 0) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue: ";
    for (int i = 0; i < queueSize; i++) {
        cout << arr[(frontIndex + i) % capacity] << ' ';
    }
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

            if (!enqueue(element)) {
                cout << "Queue is full.\n";
            }
        } else if (choice == 2) {
            int element;
            if (deque(element)) {
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