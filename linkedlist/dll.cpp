#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class doublyList {
    Node* head;
    Node* tail;
public:
    doublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_back(int val){
         Node* newNode = new Node(val);
         if(head==NULL){
             head=tail=newNode;
         }else{
             newNode->prev=tail;
             tail->next=newNode;
             tail=newNode;
         }
    }
    void pop_front(){
        if(head==NULL){
            cout<<" DLL is Empty\n";
        }
      Node* temp=head;
      head=head->next;
      if(head!=NULL){
          head->prev=NULL;
      }
      temp->next=NULL;
      delete temp;
    }
    void pop_back(){
        if(head==NULL){
            cout<<"DLL is empty\n";
        } 
        Node* temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
        }
        temp->prev=NULL;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    doublyList l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_back(4);
   l1.pop_back();
  
    l1.display();  // to verify the list

    return 0;
}
