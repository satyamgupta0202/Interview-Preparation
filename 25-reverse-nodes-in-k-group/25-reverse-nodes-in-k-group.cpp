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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int n = 0 ; 
        ListNode* temp = head ;
        vector<int>v;
        if(temp == NULL)return NULL;
        
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        
     cout<<v.size();
        
        n = v.size()-1;
        
        ListNode* ans = new ListNode(0);
        temp = ans;
        
        int i=-1 , j=0;
        while(i+k<=n){
            
            i=i+k;
            j=i;
            
            for(int p=1;p<=k;p++){
                temp->next = new ListNode(v[j--]);
                temp=temp->next;
            }
        }
        
        i+=1;
        while(i<=n){
             temp->next = new ListNode(v[i++]);
                temp=temp->next;
        }
        
        return ans->next;
        
        
    }
};