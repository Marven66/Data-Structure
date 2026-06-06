#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }

    void remove(int val) {
        if (!head) return;
        if (head->data == val) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            Node* last = head;
            while (last->next != head) last = last->next;
            Node* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next != head && curr->next->data != val)
            curr = curr->next;
        if (curr->next != head) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }
};

int main() {
    CircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    list.remove(20);
    list.display();
    return 0;
}
