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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!(fast && fast->next)) return NULL;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};


































/** Naive  approach 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
         map<ListNode* , bool >mp;
        if(head==NULL)return NULL;
        auto start = head;
        if(head->next == head )return head;
        
        mp[start]=true;
        bool ok = true;
        while(start->next!=NULL && ok){
            
            if(mp.count(start->next) == 0){
                mp[start->next]=true;
                start=start->next;
            }
            else{
                return start->next;
            }
            
        }
       return NULL; 
        
    }
};
**/
