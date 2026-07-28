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
class Solution{
public:
    ListNode* rev(ListNode* &head){
        if(head==NULL){
            return NULL;   //can also write just return
        }
        //setting prev and curr
        ListNode* prev = NULL;
        ListNode* curr = head;
        //updating links
        while(curr!=NULL){
            ListNode* forward = curr->next;   //forward jevha last node vr yeil tevha this step wont work, so staring la lihili 
            curr->next = prev;   //link todli
            prev = curr;
            curr = forward;
        }
        //update head
        head = prev;
        return head;
    }

    /*Recursion approach:
    ListNode* reverseLLRecursive(ListNode* &head, ListNode* &prev){
        if(head==NULL){
            return prev;
        }
        ListNode* curr = head;
        ListNode* forward = curr->next;
        curr->next = prev;
        //abhi tak 1 node reverse ho chuki he, baki recursion karega
        return reverseLLRecursive(forward, curr);
    }*/
    
    ListNode* reverseList(ListNode* head) {
        rev(head); 
        return head;   

        /*Recusrion:
        ListNode* prev=NULL;
        head = reverseLLRecursive(head,prev);
        return head; */           
    }
};