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
    ListNode* removeElements(ListNode* head, int val) {
     
        ListNode* dummy =  new ListNode(0);
        dummy->next = head;
        ListNode *curr=head , *prev =dummy;
        
        if(head==NULL)return NULL;
        
        while(curr->next){
            
            if(curr->val == val)
            {
                curr->val=curr->next->val;
                curr->next=curr->next->next;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        
        if(curr->val==val){
            prev->next=NULL;
        }
        
       return dummy->next;
        
    }
};