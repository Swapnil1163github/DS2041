#include<iostream>
using namespace std;

template <class T>
class Stack {
public:
    int top = -1;
    T ary[5];

    void push(T data) {
        if (top < 4) {
            top++;
            ary[top] = data;
            cout << data << " Pushed Successfully\n";
        }
        else {
            cout << "Stack Overflow\n\n";
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n\n";
        }
        else {
            cout << ary[top] << " Popped Successfully\n";
            top--;
        }
    }

    void traverse() {
        if (top == -1) {
            cout << "Stack Underflow\n\n";
        }
        else {
            for (int i = top; i >= 0; i--) {
                cout << ary[i] << " ";
            }
            cout << endl;
        }
    }
};

template <class T>
class Queue {
public:
    int front = -1, rear = -1;
    T ary[5];

    void enqueue(T data) {
        if ((front == 0 && rear == 4) || (rear == (front - 1) % 4)) {
            cout << "Queue Overflow\n";
        }
        else if (front == -1) {
            front = rear = 0;
            ary[rear] = data;
            cout << data << " Enqueued Successfully\n";
        }
        else {
            rear = (rear + 1) % 5;
            ary[rear] = data;
            cout << data << " Enqueued Successfully\n";
        }
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow\n";
        }
        else if (front == rear) {
            cout << ary[front] << " Dequeued Successfully\n";
            front = rear = -1;
        }
        else {
            cout << ary[front] << " Dequeued Successfully\n";
            front = (front + 1) % 5;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue Underflow\n";
        }
        else {
            int i = front;
            do {
                cout << ary[i] << " ";
                i = (i + 1) % 5;
            } while (i != (rear + 1) % 5);
            cout << endl;
        }
    }
};

int main() {
    char d;
    int optn;
    Stack<char> stackObj;
    Queue<char> queueObj;

    do {
        cout << "Which operation do you want to perform\n\t1 PUSH\n\t2 POP\n\t3 TRAVERSE (Stack)\n";
        cout << "\t4 ENQUEUE\n\t5 DEQUEUE\n\t6 DISPLAY (Queue)\n\t7 EXIT---->: ";
        cin >> optn;

        switch (optn) {
        case 1:
            cout << "Enter Data: ";
            cin >> d;
            stackObj.push(d);
            break;
        case 2:
            stackObj.pop();
            break;
        case 3:
            stackObj.traverse();
            break;
        case 4:
            cout << "Enter Data: ";
            cin >> d;
            queueObj.enqueue(d);
            break;
        case 5:
            queueObj.dequeue();
            break;
        case 6:
            queueObj.display();
            break;
        case 7:
            break;
        default:
            cout << "Enter Valid Choice";
        }
    } while (optn != 7);

    return 0;
}
