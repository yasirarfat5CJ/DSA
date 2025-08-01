#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = NULL;
    }
};

class queue {
    Node* head;
    Node* tail;
public:
    queue() {
        head = tail = NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return; // added this return to avoid accessing nullptr
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front() {
        if (empty()) {
            return -1;
        }
        return head->val;
    }

    bool empty() {
        return head == NULL;
    }
};

int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
