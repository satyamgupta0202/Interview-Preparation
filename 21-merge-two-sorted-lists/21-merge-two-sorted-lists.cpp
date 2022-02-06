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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head;
        ListNode* ans;
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1->val <= list2->val){
              head = new ListNode(list1->val)  ;
              list1 = list1->next;
               ans = head;
        }else{
              head = new ListNode(list2->val)  ;
              list2 = list2->next;
              ans = head;
        }
       
        while(list1 && list2){
             ListNode* temp;
             if(list1->val <= list2->val){
              temp = new ListNode(list1->val)  ;
              list1 = list1->next;
        }else{
         temp = new ListNode(list2->val)  ;
              list2 = list2->next;
          }
            
            head->next = temp;
            head = head->next;
             
        }
        
        while(list1){
           ListNode* temp = new ListNode(list1->val);
            head->next = temp;
            head = head->next;
            list1 = list1->next;
        }
        while(list2){
            ListNode* temp = new ListNode(list2->val);
            head->next = temp;
            head = head->next;
            list2 = list2->next;
        }
        
        return ans;
        
        
    }
};