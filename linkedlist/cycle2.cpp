/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
       return NULL;
    }
};


/* in this problem we have to find the npde where the cycle is startde
Approach:the approach is similar to cycle detection first we detect the cycle using fast and slow pointer
once the cycle is detected we move slow pointer to head and move fast one step 
at a time until both fast and slow meets again when they meet again that node is the starting node and return that node
*/