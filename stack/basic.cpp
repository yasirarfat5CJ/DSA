#include <iostream>
#include <vector>
using namespace std;

class stack {
    vector<int> v;

public:
    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        if (!v.empty()) {
            v.pop_back();
        }
    }

    int top() {
        if (!v.empty()) {
            return v[v.size() - 1];
        }
        return -1; // or throw an error
    }

    bool isempty() {
        return v.empty();
    }

    void display() {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display(); // Output: 1 2 3
}
