#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class OrderedLinkedList {
private:
    Node* head;
public:
    OrderedLinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head || head->data >= val) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data < val)
            curr = curr->next;
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    void remove(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != val)
            curr = curr->next;
        if (curr->next) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }
};

int main() {
    OrderedLinkedList list;
    list.insert(30);
    list.insert(10);
    list.insert(20);
    list.display();
    list.remove(20);
    list.display();
    return 0;
}
