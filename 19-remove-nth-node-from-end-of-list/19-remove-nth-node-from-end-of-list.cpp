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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *slow=dummy , *fast=dummy;
        
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};

/**             Optimized 
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
**/
