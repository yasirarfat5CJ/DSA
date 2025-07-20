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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2) return temp1;
            if(temp1==NULL) temp1=headB;
            if(temp2==NULL) temp2=headA;
        }
        return temp1;
     
        
    }
};
/* In this problem  given two list at some point the  two list gets merge into one we have to find the node where it merges
Approach: the approach to solve this  problem is we take two pointers and move them until they r not equal if they r wqaul we return the node
if temp1 reaches to null then we assing temp1 as headB and same for temp2
*/