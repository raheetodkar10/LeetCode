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
    ListNode* partition(ListNode* head, int x) {
        ListNode* fp = new ListNode(-1);   //fp list intialized to -1, same with other
        ListNode* sp = new ListNode(-1);
        auto fpTail = fp;
        auto spTail = sp;   //doni list sathi iterators

        //Step 1
        auto it = head;  //badi list ko iterate karne ke liye
        while(it){
            if(it->val < x){   //first part
                fpTail->next = it;
                fpTail = fpTail->next;
            }
            else{
                spTail->next = it;
                spTail = spTail->next;
            }
            it = it->next;
        }
        //Step 2: fp and sp merge:FP->LP->NULL
        fpTail->next=sp->next;  //ethe, fpTail tyachya last element vr ala asnar and 2nd part cha head will be sp
        //Step 3
        spTail->next=NULL;

        return fp->next;    //fp vr -1 asnar(as we initialized), so next ghayaycha
    }
};
//TC:O(n), SC:O(1)