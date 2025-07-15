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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenhead=even;
        
        while(even && even->next){
              odd->next=even->next;
              odd=odd->next;

              even->next=odd->next;
              even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};
/*
in this problem we have to make odd indices one side and even indices another side 
Approach:in this approach weuse two pointers odd ponts to head and even points to head->next
we also mak evenhead pointer to merge the odd and even LL;
we run a lopp until even and event->next is not null
in each iteration we update odd->next to even->next and update odd 
similarly for odd-next to event->next and update evenonce we exit from the lopop
we merge odd and even LL by updating odd->next  to evenhead
*/