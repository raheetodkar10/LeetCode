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
/*overall approach:
Find length.
Find middle.
Reverse the second half.
Compare first half and second half.  */

//second half la reverse karaych, in odd case: mid=mid->next 
//jr 2 pointers use kele one at start and other at end tr end wala mage nai anu shakat so not used that aprroach
    int getLen(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* rev(ListNode* &head){
        if(head==NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
        return head;
    }

    bool checkPalindrome(ListNode* head){
        //find len of LL
        int len = getLen(head);
        //find mid
        ListNode* mid = getMid(head);
        //update mid as per even/odd case
        //even case me mid as it is rahega
        //odd case me finalMid mid->next ko jayega
        ListNode* finalMid;
        if(len & 1){
            //odd
            finalMid = mid->next;
        }
        else{
            //even
            finalMid = mid;
        }
        //reverse LL starting from mid node : reverse from second half
        rev(finalMid);
        //now, i have 2 LL with pointers head and finalMid
        //compare and return true/false
        ListNode* temp = head;
        while(temp != NULL && finalMid != NULL){
            if(temp->val != finalMid->val){
                return false;
            }
            temp = temp->next;
            finalMid = finalMid->next;
        }
        //jr me ethe ale tr sagle values match zhale ie it is palindrome
        return true;

    }
    bool isPalindrome(ListNode* head) {
        return checkPalindrome(head); 
    }
};