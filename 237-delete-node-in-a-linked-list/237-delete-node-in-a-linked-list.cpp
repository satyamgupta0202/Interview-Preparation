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
    void deleteNode(ListNode* node) {
      
        node->val   = node->next->val;
        node->next = node->next->next;

    }
};

/** 
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* temp = node->next;
        
        while(temp->next)
        {
            node->val = temp->val;
            node=node->next;
            temp=temp->next;
        }
        node->val = temp->val;
        node->next=NULL;
    }
};

**/