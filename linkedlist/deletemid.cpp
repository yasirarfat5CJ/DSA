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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        int count=0;
       if (!head || !head->next) return nullptr;
        while(temp){
            count++;
            temp=temp->next;
        }
        int n=count/2;
        
        temp=head;
        for(int i=0;i<n-1;i++){
            temp=temp->next;
        }
        ListNode* delnode=temp->next;
        temp->next=temp->next->next;
        delete delnode;
        return head;
        
    }
};
/*
in this problem  we have to delete the middle node of the LL
Approcah:the brute force approach is we count the num of nodes in the LL
the we have to find the  middel of the that is count/2
again we reinitailze temp as head and run a loop until n-1;
one loop exited we make a newNode initalize with temp->next;
and update the temo->next to temp->next->next;
and we delete the node
now we will return head now;
*/