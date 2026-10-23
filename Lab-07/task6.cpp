// Muhammad Riyan Khalid | 559090 | BSCS15-2025D
#include <iostream>
using namespace std;
class LinkedDeque {
private:
    struct node {
        int data;
        node* next;
        node* prev;
    };

    node* front;
    node* rear;

public:
    LinkedDeque() {
        front = nullptr;
        rear = nullptr;
    }

    ~LinkedDeque() {
        ClearDeque();
    }

    bool IsEmpty() {
        return front == nullptr;
    }

    void InsertFront(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = front;

        if (IsEmpty()) {
            rear = newNode;
        } else {
            front->prev = newNode;
        }
        front = newNode;
        cout << "Inserted at front: " << value << endl;
    }

    void InsertRear(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = rear;

        if (IsEmpty()) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        cout << "Inserted at rear: " << value << endl;
    }

    void DeleteFront() {
        if (IsEmpty()) {
            cout << "Deque is empty. Cannot delete from front." << endl;
            return;
        }
        node* temp = front;
        int removed = temp->data;
        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        cout << "Deleted from front: " << removed << endl;
    }

    void DeleteRear() {
        if (IsEmpty()) {
            cout << "Deque is empty. Cannot delete from rear." << endl;
            return;
        }
        node* temp = rear;
        int removed = temp->data;
        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
        cout << "Deleted from rear: " << removed << endl;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Deque elements: ";
        node* curr = front;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void ClearDeque() {
        while (!IsEmpty()) {
            node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    LinkedDeque dq;
    int choice = 0;
    int val = 0;

    while (true) {
        cout << "\n===== Linked Deque Menu =====" << endl;
        cout << "1. Insert Front" << endl;
        cout << "2. Insert Rear" << endl;
        cout << "3. Delete Front" << endl;
        cout << "4. Delete Rear" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            dq.InsertFront(val);
        } else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            dq.InsertRear(val);
        } else if (choice == 3) {
            dq.DeleteFront();
        } else if (choice == 4) {
            dq.DeleteRear();
        } else if (choice == 5) {
            dq.Display();
        } else if (choice == 6) {
            dq.ClearDeque();
            cout << "Exiting program. Memory cleared." << endl;
            break;
        } else {
            cout << "Invalid choice. Select between 1 and 6." << endl;
        }
    }

    return 0;
}