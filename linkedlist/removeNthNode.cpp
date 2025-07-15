/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(n==count){
            ListNode* newhead=head->next;
            delete head;
            return newhead;
        }
        temp=head;
        for(int  i=0;i<count-n-1;i++){
           temp=temp->next;
        }
        ListNode* prev=temp->next;
        temp->next=temp->next->next;
        delete prev;
        
        return head;
    }
};
/*
in this problem we r given a head and integer and n we gave to delete the  node  nth from the end of the list
Approach:the brute force approach we count the num of nodes in LL
then we check  if n is equal to  count then we make an newhead as head->next
and delete the  head and return the newhead 
again we reinitailize the temp to head and run a loop until n-count-1
once the loop ends we make one pointer initialize with temp->next
and update the temp to temp->next->next and delete the pointer return the head
*/