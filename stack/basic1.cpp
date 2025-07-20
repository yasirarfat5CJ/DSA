#include <iostream>
#include <list>  // ✅ Needed for std::list
using namespace std;

class stack {
    list<int> ll;

public:
    void push(int val) {
        ll.push_front(val); // O(1)
    }

    void pop() {
        if (!ll.empty())
            ll.pop_front(); // O(1)
    }

    int top() {
        if (!ll.empty())
            return ll.front();
        return -1; // Or throw exception
    }

    bool isempty() {
        return ll.empty();
    }

    void display() {
        for (int val : ll) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display(); // Output: 3 2 1 (LIFO order)
}
