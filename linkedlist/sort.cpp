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
      ListNode* getmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
      }
      ListNode* merge(ListNode* left,ListNode* right){
        ListNode dummy(-1);
        ListNode* tail=&dummy;
        while(left && right){
            if(left->val<=right->val){
                tail->next=left;
                left=left->next;
            }else{
                tail->next=right;
                right=right->next;
            }
            tail=tail->next;
        }
        tail->next=(left?left:right);
        return dummy.next;
      }
   
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* middle=getmiddle(head);
         ListNode* right=middle->next;
         middle->next=NULL;
          
          ListNode* leftSort=sortList(head);
          ListNode* rightSort=sortList(right);
          return merge(leftSort,rightSort);
        
    }
};
/*In this problem we need to sort the list.
we will apply merge sort to sove this problem.
*/