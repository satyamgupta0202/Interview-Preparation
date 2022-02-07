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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        if(!l1)return l2;
        if(!l2)return l1;
        
        ListNode* Dummy = new ListNode(0);
        int carry = 0;
        ListNode* head = Dummy;
        
        while(l1 && l2){
           
            int num = l1->val + l2->val + carry;
            int k = num%10;
            carry = num/10;
            
            head->next = new ListNode(k);
            head = head->next;
            l1=l1->next;
            l2=l2->next;
            
        }
        
        while(l1){
            
           int num = l1->val  + carry;
            int k = num%10;
            carry = num/10;
            
            head->next = new ListNode(k);
            head = head->next;
            l1=l1->next;
           
            
        }
           while(l2){
           int num = l2->val  + carry;
            int k = num%10;
            carry = num/10;
            
            head->next = new ListNode(k);
            head = head->next;
            l2=l2->next;
           
            
        }
        
        if(carry>0){
            head->next = new ListNode(carry);
        }
        
        return Dummy->next;
        
        
    }
};