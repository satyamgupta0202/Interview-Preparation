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
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL)return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // cout<<slow->val;
        // cout<<endl;
        // cout<<fast->val;
        
       
        ListNode* prev = NULL ;
        ListNode* curr = slow;
        ListNode *next;
        
        while(curr){
            
            next = curr->next;    
            curr->next = prev;
            prev = curr;
            curr=next;
        
        }
        
        
        //prev , lol
       
        while(prev && head){
            
            if(prev->val != head->val)return false;
            
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};






/**     Naive Aproach
class Solution {
public:
    
    bool check(vector<int>&v){
        int n = v.size();
        int i=0,j = n-1;
        while(i<=j){
            if(v[i]!=v[j])return false;
            i++;
            j--;
        }
        return true;
    }
    
    
    bool isPalindrome(ListNode* head) {
        
        vector<int>v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        
        return check(v);
    }
};
**/