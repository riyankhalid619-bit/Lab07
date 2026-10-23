#include <iostream>
using namespace std;
class CircularQueue {
private:
    int arr[5];
    int front;
    int rear;

public:
    CircularQueue() {
        front=-1;
        rear=-1;
    }

    bool IsEmpty() {
        return front==-1;
    }

    bool IsFull() {
        return (rear + 1) % 5 == front;
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Circular Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % 5;
        }
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Circular Queue is empty. Cannot dequeue." << endl;
            return;
        }
        int removed = arr[front];
        cout << "Dequeued: " << removed << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 5;
        }
    }

    void Peek() {
        if (IsEmpty()) {
            cout << "Circular Queue is empty. Nothing to peek." << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Circular Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % 5;
        }
        cout << "(front = " << front << ", rear = " << rear << ")" << endl;
    }
};

int main() {
    CircularQueue cq;

    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);
    cq.Enqueue(40);
    cq.Enqueue(50);

    cq.Dequeue();
    cq.Dequeue();

    cq.Enqueue(60);
    cq.Enqueue(70);

    cq.Display();

    cq.Enqueue(80);

    cq.Dequeue();
    cq.Dequeue();
    cq.Dequeue();
    cq.Dequeue();
    cq.Dequeue();

    cq.Dequeue();

    cq.Enqueue(100);
    cq.Display();

    return 0;
}