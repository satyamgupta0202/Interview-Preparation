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
    ListNode *detectCycle(ListNode *head) {
        
        if(!head)return NULL;
        ListNode* slow = head;
        ListNode* fast = head ;
        
        if(slow->next == NULL || fast->next==NULL || fast->next->next==NULL)return NULL;
        
        
        while( fast->next && fast->next->next){
            
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)break;  
        }  
        
        if(!slow || !fast)return NULL;
       
        if(slow && fast && slow==fast){
        fast = head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        }
        
        
        
        return NULL;
    }
};



































/** Naive  approach 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
         map<ListNode* , bool >mp;
        if(head==NULL)return NULL;
        auto start = head;
        if(head->next == head )return head;
        
        mp[start]=true;
        bool ok = true;
        while(start->next!=NULL && ok){
            
            if(mp.count(start->next) == 0){
                mp[start->next]=true;
                start=start->next;
            }
            else{
                return start->next;
            }
            
        }
       return NULL; 
        
    }
};
**/
