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