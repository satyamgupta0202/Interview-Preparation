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
    
    void rev(ListNode *start , ListNode *end){
        
        ListNode* prev = NULL ;
        ListNode* curr = start ;
        ListNode* next = NULL;
        
        while(prev!=end){ 
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
         
        }
    }
    
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        //check
        
        while(k==1 || head==NULL || head->next==NULL)return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        
        ListNode* start = dummy , *end = head;
        int i=0;
        
        while(end!=NULL){
            
            i++;
            if(i%k==0){
                ListNode* temp = end->next,*s = start->next;
                rev(s , end);
                
                start->next = end;
                s->next = temp;
                
                start = s;
                end = temp;  
            }
            else{
                end=end->next;
            }
            
        }
         return dummy->next;  
    }
};





/**
 ListNode* temp = head;
        for(int i=0;i<k;i++){
            if(temp==NULL)return head;
            temp=temp->next;
        }
        
        int cnt = 0;
        ListNode *prev = NULL, *next = NULL , *curr = head;
        
        while(cnt<k && curr){
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
            cnt++;
        }
        
        if(next){
            head->next = reverseKGroup(curr,k);
        }   
        return prev;    
**/


//mathod 1 simple naive
/**
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
**/