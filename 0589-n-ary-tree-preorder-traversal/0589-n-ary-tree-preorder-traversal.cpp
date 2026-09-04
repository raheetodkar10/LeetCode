/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root, vector<int> &ans){  //Root Left Right
        if(root == NULL) return;
        ans.push_back(root->val);
        //normal binary preorder sarkh nai kru shakat as there are multiple children. So we need to iterate thro children
        for(auto child : root->children){
            solve(child,ans);  //ethe root->child nai lihu shakat, karn n ary tree does not have just 1 child, it has a vector of children
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;  
    }
};