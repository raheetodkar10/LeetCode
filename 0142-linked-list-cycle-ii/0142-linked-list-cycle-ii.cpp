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
        unordered_map<ListNode*, bool> visited;
        ListNode* temp = head;
        while(temp != NULL){     //it will be false in case of a cycle
            if(visited[temp] == true){    //jr node already visit kela asel tr toch starting asnar
                return temp;
            }
            else{
                visited[temp] = true;
                temp = temp->next; 
            }
        }
        //jr ethe ale tr temp == null zhal asnar ie no loop
        return NULL;
        
    }
};