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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL)return NULL;
      
        int cnt = 1;
        ListNode* temp = head;
        
        while(temp->next){
            cnt++;
            temp = temp->next;    
        }
        
        k = k%cnt;
        if(k==0)return head;
        
        int tar = cnt - k;
        cnt = 0;
        ListNode* prev = head ;
        ListNode* curr = head;
        
        while(cnt!=tar){
            prev = curr ;
            curr=curr->next;
            cnt++;
        }
        
        prev->next = NULL;
        ListNode* ans = curr;
        
        // while(curr->next!=NULL){
        //     curr=curr->next;
        // }
        temp->next = head;
        return ans;
    
    }
};