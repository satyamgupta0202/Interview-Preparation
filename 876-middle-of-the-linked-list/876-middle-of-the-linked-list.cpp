
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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*>v;
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            v.push_back(temp);
            temp=temp->next;
        }
        return (v[cnt/2]);
    }
};