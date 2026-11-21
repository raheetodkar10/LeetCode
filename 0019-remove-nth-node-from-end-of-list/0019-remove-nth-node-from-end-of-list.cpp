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
    ListNode* removeNthFromEnd(ListNode* head, int n) {  //TC:O(N), SC:O(1)
        //yat apn dummy node banavnar at start of node, karn jr start node delete karaychi asel tr we can do it safely ani dusrya conditions lavavya nai lagnar
        //two pointers: slow & fast
        //fast la n steps ani slow la 1 step chalvaych. jevha fast last node la asel tevha slow delete karaychya node chya 1 step mage asnar(slow.next=slow.next.next)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        //move fast n steps ahead
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        while(fast->next != NULL){  //move them together
            slow = slow->next;
            fast = fast->next;
        }
        //delete nth node from end
        slow->next = slow->next->next;   //slow->next: node that we want to delete. it will be removed from ll
        //return new head(skip dummy)
        return dummy->next;
    }
};