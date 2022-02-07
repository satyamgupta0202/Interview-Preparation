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
    int getDecimalValue(ListNode* head) {
        
        int n = 0;
        ListNode* temp = head;
        
        // while(temp){
        //     n++;
        //     temp = temp->next;
        // }
        
       int ans = 0;
       temp = head;
        while(temp){
           ans = ans*2;
            ans+= temp->val;
            temp=temp->next;
        }
        return ans;
    }
};