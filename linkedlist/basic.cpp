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

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void insert(int pos,int val){
        if(pos<0){
            return;
        }
        if(pos==0){
            push_front(val);
            return;
        }else{
            Node* newNode=new Node(val);
            Node* temp=head;
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
        
    }
    void pop_front(){
        if(head==NULL){
            cout<<"List is Empty\n";
        }else{
           Node* temp=head;
           head=temp->next; 
           delete temp;
        }
        
    }
    void pop_back(){
        Node* temp=head;
        if(head==NULL){
            cout<<"LIST is EMPTY\n";
        }else{
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
            tail=temp;
        }
    }
    int search(int key){
        Node* temp=head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }
    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
};

int main() {
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.insert(1,9);
  cout<<"\n"<<l1.search(2);
    l1.printLL();  // Output: 3 2 1

    return 0;
}


/*
it is the basic of singly linked list where i learn creation and insertiom and deletionof linked list
*/
