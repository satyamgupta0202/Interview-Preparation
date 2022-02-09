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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode*temp = new ListNode(-1);
        temp->next = head;
       
        ListNode* prev = head;
        while(head!=NULL){
            
              prev = head;
              int k = head->val;
              while(head && head->val==k)head=head->next;
            
              prev->next = head;
            
            
        }
        
        return temp->next;
        
        
    }
};