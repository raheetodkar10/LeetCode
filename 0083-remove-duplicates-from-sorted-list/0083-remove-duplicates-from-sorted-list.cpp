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
    ListNode* deleteDuplicates(ListNode* head) {
        //empty LL
        if(head == NULL){
            return head;
        }
        //single node
        if(head->next == NULL){
            return head;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != NULL){
            if(curr->val != prev->val){  //not duplicate
                curr = curr->next;
                prev = prev->next;
            }
            else{      //duplicate
                prev->next = curr->next;
                curr->next = NULL;  //isolate
                delete curr;
                curr=prev->next;  //curr delete hoto so to parat re-initialize karava lagnar for further operations
            }
        }
        return head;
        
    }
};