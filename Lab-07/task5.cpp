#include <iostream>
using namespace std;
class ArrayDeque {
private:
    int arr[5];
    int front;
    int rear;

public:
    ArrayDeque() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() {
        return front == -1;
    }

    bool IsFull() {
        return (rear + 1) % 5 == front;
    }

    void InsertFront(int value) {
        if (IsFull()) {
            cout << "Deque is full. Cannot insert " << value << " at front." << endl;
            return;
        }
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            front = (front + 5 - 1) % 5;
        }
        arr[front] = value;
        cout << "Inserted at front: " << value << endl;
    }

    void InsertRear(int value) {
        if (IsFull()) {
            cout << "Deque is full. Cannot insert " << value << " at rear." << endl;
            return;
        }
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % 5;
        }
        arr[rear] = value;
        cout << "Inserted at rear: " << value << endl;
    }

    void DeleteFront() {
        if (IsEmpty()) {
            cout << "Deque is empty. Cannot delete from front." << endl;
            return;
        }
        int removed = arr[front];
        cout << "Deleted from front: " << removed << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 5;
        }
    }

    void DeleteRear() {
        if (IsEmpty()) {
            cout << "Deque is empty. Cannot delete from rear." << endl;
            return;
        }
        int removed = arr[rear];
        cout << "Deleted from rear: " << removed << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear = (rear + 5 - 1) % 5;
        }
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Deque elements: ";
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
};

int main() {
    ArrayDeque dq;

    dq.InsertRear(20);
    dq.InsertFront(10);
    dq.InsertRear(30);
    dq.Display();

    dq.DeleteRear();
    dq.DeleteFront();
    dq.Display();

    dq.InsertFront(5);
    dq.InsertRear(30);
    dq.InsertRear(40);
    dq.InsertFront(1);
    dq.Display();

    dq.InsertFront(99);
    dq.InsertRear(100);

    ArrayDeque testRun1;
    testRun1.InsertRear(500);
    testRun1.DeleteFront();
    testRun1.DeleteFront();

    ArrayDeque testRun2;
    testRun2.InsertFront(600);
    testRun2.DeleteRear();
    testRun2.DeleteRear();

    return 0;
}