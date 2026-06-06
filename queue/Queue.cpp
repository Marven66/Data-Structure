#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front, rear, capacity;
public:
    Queue(int size) : capacity(size), front(0), rear(0) {
        arr = new int[capacity];
    }

    ~Queue() { delete[] arr; }

    void enqueue(int val) {
        if (rear == capacity) return;
        arr[rear++] = val;
    }

    void dequeue() {
        if (front == rear) return;
        front++;
    }

    int peek() {
        return (front == rear) ? -1 : arr[front];
    }

    bool isEmpty() {
        return front == rear;
    }

    void display() {
        for (int i = front; i < rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    cout << "Front: " << q.peek() << endl;
    return 0;
}
