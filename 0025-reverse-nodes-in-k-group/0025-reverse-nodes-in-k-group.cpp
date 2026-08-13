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
    /* for queue:
    void revUsingQueue(queue<int>& q,int k, queue<int>& ans, int unUsedElemCount){
        //lets find whether we have k elem to reverse or not
        if(unUsedElemCount >= k){
            //1 case
            stack<int> s;
            for(int i=0;i<k;i++){
                int elem = q.front();
                q.pop();
                s.push(elem);
            }
            //put them back in reversed order
            while(!s.empty()){
                ans.push(s.top());
                s.pop();
            }
            //baki recursion
            revUsingQueue(q,ans, k,unUsedElemCount-k);   //apn unUsedElemCount sobat 1 case handle keli, ata unUsedElemCount-k sobat recursion handle karel
        }
        else{
            //no k grp to reverse, so return it as it is
            for(int i=0;i<unUsedElemCount;i++){
                int elem = q.front();
                q.pop();
                q.push(elem);
            }
            while(!q.empty()) {
                ans.push(q.front());
                q.pop();
            }
            return;
        }
    }*/
    ListNode* reverseKGroup(ListNode* head, int k) {
        /* for queue:
        queue<int>q;
        queue<int> ans;
        // Put linked-list elements into queue
        ListNode* temp = head;
        while(temp != NULL) {
            q.push(temp->val);
            temp = temp->next;
        }
        // Reverse groups
        revUsingQueue(q, ans, k, q.size());
        // Put queue values back into linked list
        temp = head;
        while(temp != NULL) {
            temp->val = ans.front();
            ans.pop();

            temp = temp->next;
        }
        return head;*/
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