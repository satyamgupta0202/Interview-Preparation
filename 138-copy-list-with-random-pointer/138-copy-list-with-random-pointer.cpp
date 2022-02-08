/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head; 
          Node *front = head;

          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
          while (iter != NULL) {
            front = iter->next;

            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
          }

          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
          }

          // Third round: restore the original list, and extract the copy list.
          iter = head;
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

          while (iter != NULL) {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;
              
            copy = copy -> next; 
            iter = front;
          }

          return pseudoHead->next;
    }
};























//Method 1 o(N) space complexity
/**
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        map<Node* , Node*>mp;
        Node* temp = head;
        int cnt=0;
        
        while(temp){
            mp[temp]= new Node(temp->val);
            temp=temp->next;
        }
        
        
        
        temp = head;
        
        while(temp){
           mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp=temp->next;
        }
 
        return mp[head];
        
    }
};
**/