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
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        
        ListNode *a = l1 , *b = l2;
        
        while(a!=b){
            
            if(a==NULL){
                a=l2;
            }else{
                a=a->next;
            }
            
            if(b==NULL){
                b = l1;
            }else{
                b = b->next;
            }
            
        }
        
        return a;
        
        
        
    }
};

/**
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        
        set<ListNode*>s;
        ListNode* temp = l1;
        while(temp!=NULL){
            s.insert(temp);
            temp = temp->next;
        }
        
        temp =  l2;
        while(l2){
            if(s.count(l2))return l2;
            l2=l2->next;
        }
        return NULL;
    }
};
**/