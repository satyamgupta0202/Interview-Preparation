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
        
        //rabbit tortoise method
        
       if(head==NULL)return false;     //base case to be remenbered
        
       ListNode* slow = head;
       ListNode* fast = head->next;
        
    
        while(slow && fast && slow != fast){
            slow = slow->next;
            if(fast->next==NULL)return false;    //note this too
            fast = fast->next->next;
        }
        
        if(slow!=NULL && slow==fast)return true;
        return false;
        
    }
};

/**
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
**/