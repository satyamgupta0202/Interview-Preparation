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
    
    ListNode* solve(ListNode* head)
    {
        if(head == NULL)return NULL;
        
        if(head->next == NULL)return head;
        
        
        ListNode* rn = solve(head->next->next);

        ListNode* temp = head->next;
        head->next->next = head;
        head->next = NULL;
        
        head->next = rn ;
        
        return temp;
    }
    
    
    ListNode* swapPairs(ListNode* head) 
    {
        return solve(head);
        
    }
};