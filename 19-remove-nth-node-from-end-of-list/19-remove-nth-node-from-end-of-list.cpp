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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        
        ListNode* temp = head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
     
        int target = n-k+1;
        int cnt=1;
        temp=head;
        ListNode* prev = head;
        while(cnt!=target){
            prev =temp;
            temp=temp->next;
            cnt++;
        }
        
        if(cnt==1)return head->next;
        
       prev->next=temp->next;
    
        
        
        return head;
    }
};