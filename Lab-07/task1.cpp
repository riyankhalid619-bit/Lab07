#include <iostream>
using namespace std;
class ArrayQueue {
private:
    int arr[5];
    int front;
    int rear;

public:
    ArrayQueue() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() {
        return front == -1;
    }

    bool IsFull() {
        return rear == 4;
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        int removed = arr[front];
        cout << "Dequeued: " << removed << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void Peek() {
        if (IsEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    q.Dequeue();
    q.Dequeue();

    q.Enqueue(60);

    q.Display();

    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    q.Dequeue();

    q.Enqueue(70);
    q.Display();

    return 0;
}