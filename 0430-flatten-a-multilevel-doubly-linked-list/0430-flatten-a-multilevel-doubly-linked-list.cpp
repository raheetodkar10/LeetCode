/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head){
        if(head == NULL) return NULL;
        auto it = head;
        auto tail = head;
        while(it){   //joparyant it null nai hot
            if(it->child){
                auto childTail = solve(it->child);

                auto temp = it->next;
                it->next = it->child;
                it->next->prev = it;
                childTail->next = temp;
                if(temp != NULL)  
                    temp->prev = childTail;
                it->child = NULL;
            }
            tail = it;   //it null hou shakto, vo node return karni he jiska next null ho ie child tail  (to get tail)
            it = it->next;
        } 
        return tail;  //we want child tailreturn tail; 
    }

    Node* flatten(Node* head) {
        solve(head);
        return head;    
    }
};