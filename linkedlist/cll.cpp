#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class circularList {
    Node* head;
    Node* tail;
public:
    circularList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;  // Only node, points to itself
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;  // Maintain circular link
        }
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "Circular Linked List is empty\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }
    void deleteAthead(){
        Node* temp=head;
        if(head==NULL){
            cout<<"cll is empty\n";
        }else if(head==tail){
            head=tail=NULL;
            delete head;
            
        }
        else{
            head=head->next;
            temp=tail->next;
            tail->next=head;
            delete temp;
        }
    }
    void deleteAtTail(){
        if(head==NULL){
            cout<<"cll is empty\n";
        }
        else if(head==tail){
            head=tail=NULL;
            delete head;
        }
        Node* temp=tail;
        Node* prev=head;
        while(prev->next!=tail){
            prev=prev->next;
        }
        tail=prev;
        tail->next=head;
        delete temp;
        
        
        
    }
};

int main() {
    circularList l1;
    l1.insertAtHead(1);
    l1.insertAtHead(2);
    l1.insertAtHead(3);
    l1.insertAtTail(4);
   l1.deleteAtTail();

    l1.display();

    return 0;

}