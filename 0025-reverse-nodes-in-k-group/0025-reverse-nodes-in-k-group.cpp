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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //check group of len k
        int count=0;
        ListNode* temp = head;
        while(temp != NULL && count < k){
            temp = temp->next;
            count++;
        }
        //if group exists
        if(count==k){
            //k size group exists, reverse 1 group baki recursion sambhal lega
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* forward = NULL;
            //we need to reverse only k nodes
            int i=0;
            while(i<k){
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
                i++; 
            }
            //ek group ko reverse kr diya he, baki recursion
            ListNode* recursionHead = reverseKGroup(forward, k);
            //done LL ko join kardo
            head->next = recursionHead;
            //return starting node of updated list, tyamde prev starting la asnar
            return prev;
        }
        else{
            //jr k size cha group exist nasel karat
            return head;
        }
        
    }
};