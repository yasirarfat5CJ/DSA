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
    bool isPalindrome(ListNode* head) {
       if(head==NULL || head->next==NULL){
        return true;
       }
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
       }
       ListNode* prev=NULL;
       while(slow){
        ListNode* next=slow->next;
        slow->next=prev;
        prev=slow;
        slow=next;
       }
       ListNode* left=head;
       ListNode* right=prev;
       while(right){
        if(left->val!=right->val){
            return false;
        }
        left=left->next;
        right=right->next;
       }
       return true;
    }
};
/*In this problem we have to check whether the given list is palindrmic or not
Approach:first we find  the middle of the list next we reverse the second half of the list
after that we compare first and second half of the list 
if they are equal then we say that list is palindromic else not a palindromic
*/