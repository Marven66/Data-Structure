#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;
public:
    Stack(int size) : capacity(size), top(-1) {
        arr = new int[capacity];
    }

    ~Stack() { delete[] arr; }

    void push(int val) {
        if (top == capacity - 1) return;
        arr[++top] = val;
    }

    void pop() {
        if (top == -1) return;
        top--;
    }

    int peek() {
        return (top == -1) ? -1 : arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    cout << "Top: " << s.peek() << endl;
    return 0;
}
