#include <iostream>
using namespace std;
class CircularQueue {
private:
    int arr[5];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() {
        return front == -1;
    }

    bool IsFull() {
        return (rear + 1) % 5 == front;
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % 5;
        }
        arr[rear] = value;
    }

    int Dequeue() {
        if (IsEmpty()) {
            return -1;
        }
        int removed = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 5;
        }
        return removed;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % 5;
        }
        cout << endl;
    }

    void RotateTurn() {
        if (IsEmpty()) {
            cout << "Cannot rotate: No students in queue." << endl;
            return;
        }
        if (front == rear) {
            cout << "Student served: " << arr[front] << endl;
            cout << "Only one student in queue." << endl;
            Display();
            return;
        }
        int served = Dequeue();
        Enqueue(served);
        cout << "Student served: " << served << endl;
        Display();
    }
};

int main() {
    CircularQueue labQueue;

    labQueue.Enqueue(101);
    labQueue.Enqueue(102);
    labQueue.Enqueue(103);

    cout << "Initial Queue:" << endl;
    labQueue.Display();
    cout << endl;

    for (int turn = 1; turn <= 5; turn++) {
        cout << "Turn " << turn << ":" << endl;
        labQueue.RotateTurn();
        cout << endl;
    }

    CircularQueue emptyQueue;
    cout << "Testing Empty Queue:" << endl;
    emptyQueue.RotateTurn();
    cout << endl;

    CircularQueue singleQueue;
    singleQueue.Enqueue(999);
    cout << "Testing Single Student Queue:" << endl;
    singleQueue.RotateTurn();

    return 0;
}