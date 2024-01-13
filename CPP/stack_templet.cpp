#include <iostream>

using namespace std;

// Class template for Stack
template <class T>
class Stack {
private:
    static const int MAX_SIZE = 100;
    T items[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(T data) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        items[++top] = data;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return T();
        }
        return items[top--];
    }
};

// Class template for Queue
template <class T>
class Queue {
private:
    static const int MAX_SIZE = 100;
    T items[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(T data) {
        if (front == -1)
            front = 0;
        if (rear == MAX_SIZE - 1) {
            cout << "Queue overflow" << endl;
            return;
        }
        items[++rear] = data;
    }

    T dequeue() {
        if (front == -1) {
            cout << "Queue underflow" << endl;
            return T();
        }
        T data = items[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return data;
    }
};

// Main Function
int main() {
    Stack<int> stack;
    Queue<char> queue;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "From stack: " << stack.pop() << endl;

    queue.enqueue('A');
    queue.enqueue('B');
    queue.enqueue('C');

    cout << "From queue: " << queue.dequeue() << endl;

    return 0;
}
