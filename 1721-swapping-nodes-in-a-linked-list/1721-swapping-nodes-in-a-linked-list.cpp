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
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode* temp = head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        
        int cnt = 0;
        
        while(temp!=NULL)
        {
          
            cnt++;
            if(cnt==k)
            {
                a=temp;
                cout<<a->val<<endl;
            }
            temp=temp->next;
        }
        
        int kk = cnt-k;
        
        temp =  head;
        
        cnt = 0;
         while(temp!=NULL)
        {
          
            cnt++;
            if(cnt==kk+1)
            {
                b=temp;
            }
            temp=temp->next;
        }
        
        swap(a->val,b->val);
        
        return head;
        
        
        
    }
};