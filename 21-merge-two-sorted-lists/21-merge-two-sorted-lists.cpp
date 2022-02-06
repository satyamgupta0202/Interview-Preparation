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
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        ListNode dummy(0);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};





// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
//         if(list1==NULL)return list2;
//         if(list2==NULL)return list1;
//          ListNode* head = list1->val <= list2->val? list1 : list2; ;
        
//         if(list1->val <= list2->val)head->next = mergeTwoLists(list1->next,list2);
//         if(list1->val > list2->val)head->next = mergeTwoLists(list1,list2->next);
        
//         return head;
        
//     }
// };


/**
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
**/