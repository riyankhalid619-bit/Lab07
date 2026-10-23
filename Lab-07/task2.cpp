#include <iostream>
using namespace std;
class LinkedQueue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;
public:
    LinkedQueue() {
        front = nullptr;
        rear = nullptr;
    }

    ~LinkedQueue() {
        ClearQueue();
    }

    bool IsEmpty() {
        return front == nullptr;
    }

    void Enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (IsEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        int removed = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        cout << "Dequeued: " << removed << endl;
    }

    void Peek() {
        if (IsEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* curr = front;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void ClearQueue() {
        while (!IsEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    LinkedQueue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.Dequeue();
    q.Display();
    q.Peek();

    q.Dequeue();
    q.Dequeue();

    q.Dequeue();

    q.Enqueue(50);
    q.Display();

    q.ClearQueue();

    return 0;
}