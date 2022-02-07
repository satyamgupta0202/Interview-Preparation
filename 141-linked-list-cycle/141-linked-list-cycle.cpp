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
    bool hasCycle(ListNode *head) {
        
//      Naive Approach
        map<ListNode* , bool >mp;
        ListNode* temp = head;
        while(head){
            if(mp[head])return true;
            mp[head]=true;
            head = head->next;
        }
        return false;
    }
};