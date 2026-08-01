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
public:   //TC: O(n): n is length of bigger LL, SC:O(1)
    ListNode* iterative(ListNode* l1, ListNode* l2){
        auto ans = new ListNode(-1);  //ListNode* ans lihaychi garaj nahi as new ListNode(-1) will return ListNode* kyuki new ek pointer return karta he
        auto it = ans;
        int c = 0; //carry
        while (l1 || l2 || c){   //joparyant l1 or l2 or c non null ahe mhanje kahi na kahi values ahet 
            int a = l1 ? l1->val : 0;   //jr l1 non null ahe tr l1 chi value ghena sense karta naitr 0 assume kara 
            int b = l2 ? l2->val : 0;
            int sum = a + b + c;
            int digit = sum % 10;
            c = sum / 10;
            //store digit in ans LL
            it->next = new ListNode(digit);
            it = it->next;
            l1 = l1 ? l1->next : 0;   //apn l1=l1->next lihu shaklo asto pn jr l1 null asel tr this statement would be wrong, so for safety: jr l1 non null ahe tr ch l1 ch next ghya naitr null
            l2 = l2 ? l2->next : 0;
        }
        return ans->next;   //ans -1 asnar so
    }

    /*Recursion approach:  TC: O(n): n is length of bigger LL, SC:O(n)
    ListNode* recursive(ListNode* l1, ListNode* l2, int carry=0){     //initially carry=0 so default parameter
        if(!l1 && !l2 && !carry) return NULL;
        //adding first node
        int a = l1 ? l1->val : 0;   
        int b = l2 ? l2->val : 0;
        int sum = a + b + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode* ans = new ListNode(digit);
        //baki recusrion
        ans->next = recursive(l1 ? l1->next : l1, l2 ? l2->next : l2, carry);  //this recursive call will return nodes, mhanun ans->next mde nodes takle kich LL complete honar
        //l1 ? l1->next : l1: l1 null zhala asnar so l1 ch pathavla, jari 0 pass kela instead of l1 tari run honar
        return ans;
    }*/

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {   
        return iterative(l1,l2); 
        //recursion : return recursive(l1, l2);
    }
};