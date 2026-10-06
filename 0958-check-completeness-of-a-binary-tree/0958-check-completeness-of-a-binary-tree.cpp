/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        //level order traversal
        //logic:
        //if there exists any elem after NULL, not CBT
        //if there exists no elem after NULL, it is CBT
        queue<TreeNode*> q;
        //initial state
        q.push(root);
        bool nullFound = false;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL){
                nullFound = true;
            }
            else{
                //agar ye valid elem se pehle kabhi null mila tha iska mtlb CBT nai he
                if(nullFound == true){
                    return false;
                }
                //muze ek valid elem mila he
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};