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

class compare{    //created min heap
    public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {   //TC:O(n)
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* head = NULL;  //new LL
        ListNode* tail = NULL;
        
        //process first k elem
        //hr list ka pehla elem pq me insert krna he
        for(int row=0;row<lists.size();row++){
            ListNode* temp = lists[row];
            if(temp != NULL){
                //if its a valid node
                pq.push(temp);
            }
        }
        //main logic
        while(!pq.empty()){
            //front nikalo
            ListNode* front = pq.top();
            pq.pop();
            //ans me insert kro
            if(head == NULL && tail == NULL){
                //means im inserting first node in LL
                head = front;
                tail = front;
                //agar aage node he to pq me insert kro
                if(tail->next != NULL){
                    pq.push(tail->next);
                }
            }
            else{
                //means its not the first node
                tail->next = front;
                tail = front;
                //agar aage node he to pq me insert kro
                if(tail->next != NULL){
                    pq.push(tail->next);
                }
            }
        }
        return head;
        
    }
};