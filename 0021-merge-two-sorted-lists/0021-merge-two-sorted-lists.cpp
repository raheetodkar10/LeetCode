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
    class compare{  //creates min heap
        public:
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val; 
            }
    };

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* head = NULL;
        ListNode* tail = NULL;

        //insert all nodes of list1
        ListNode* temp1 = list1;
        while(temp1 != NULL){
            pq.push(temp1);
            temp1 = temp1->next;
        }
        //insert all nodes of list2
        ListNode* temp2 = list2;
        while(temp2 != NULL){
            pq.push(temp2);
            temp2 = temp2->next;
        }

        //main logic
        while(!pq.empty()){
            //front nikalo
            ListNode* front = pq.top();
            pq.pop();
            //inserting first node in LL
            if(head == NULL){
                head = front;
                tail = front;
                /*agar aage node he to pq me insert kro
                if(tail->next != NULL){
                    pq.push(tail->next);
                }*/
            }
            else{
                //means its not the first node
                tail->next = front;
                tail = front;
                /*agar aage node he to pq me insert kro
                if(tail->next != NULL){
                    pq.push(tail->next);
                }*/
            } 
            //remove old link to prevent cycles, removes runtime error
            tail->next = NULL;   
        }
        return head;
    }
};
/*Appr 2:
        ListNode* temp = new ListNode;
        ListNode* tail = temp;
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1 != NULL){
            tail->next = list1;
        }
        else{
            tail->next = list2;
        }
        ListNode* head = temp->next;
        return head;  */