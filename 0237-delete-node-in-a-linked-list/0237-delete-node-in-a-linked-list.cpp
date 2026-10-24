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
    void deleteNode(ListNode* node) {
        //ex: 4->5->1->9 , node=5 to del
        ListNode* temp = node->next;  //copy next node's val(1) in given node
        node->val = temp->val;   //val of temp is 1, so val of node changes from 5 to 1. list: 4->1->1->9
        node->next = temp->next;  //isolate: skip next node, temp->next points to node containing 9
        delete temp;
        //Copy the next node's value → Skip the next node → Delete the next node
    }
};