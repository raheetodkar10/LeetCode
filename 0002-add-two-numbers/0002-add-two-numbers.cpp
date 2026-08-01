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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {   
        return iterative(l1,l2); 
    }
};