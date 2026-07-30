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
        //if no cycle, fast = null
        //if yes cycle, slow=fast
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){  //jr fast ajun pn null nahey
                fast = fast->next;  
                //slow la tevhach pudhe nyaych jevha fast 2 steps pudhe gela asel
                slow = slow->next;
                //check meeting condition
                if(slow==fast){
                    return true;
                }
            }
        }
        //loop se tabhi bahar ayega jab fast null hoga
        return false;
    }
};