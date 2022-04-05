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
    int findTheWinner(int n, int k)
    {
        if(k==1)return n;
        ListNode* node = new ListNode(1);
        ListNode* head = node;
        for(int i=2;i<=n;i++)
        {
            node->next = new ListNode(i);
            node = node->next;
        }
        
        ListNode* temp = head;
        node->next = head;
        ListNode* prev = head;
    
        while(temp->next != temp)
        {
            int cnt = 0;
            while(cnt!=k-1)
            {
                prev = temp;
                temp=temp->next;
                cnt++;
            }
            

            
               temp = temp->next;
               prev->next = temp;      
   
        }
        return temp->val;
        
    }
};