#include <iostream>
using namespace std;

class Circularqueue {
    int* arr;
    int currSize, cap;
    int f, r;

public:
    Circularqueue(int size) {
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int data) {
        if (currSize == cap) {
            cout << "Circular queue is full\n";
            return;
        }
        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop() {
        if (empty()) {
            cout << "Circular queue is empty\n";
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }

    int front() {
        if (empty()) {
            cout << "Circular queue is empty\n";
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return currSize == 0;
    }
};  // <-- missing semicolon was here

int main() {
    Circularqueue c(3);
    c.push(1);
    c.push(2);
    c.push(3);

    cout << "Front element: " << c.front() << endl;
    c.pop();
    
    c.push(4); // To test circular behavior
    
    while (!c.empty()) {
        cout << c.front() << " ";
        c.pop();
    }
    cout << endl;

    return 0;
}
