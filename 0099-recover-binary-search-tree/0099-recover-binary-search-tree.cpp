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
    TreeNode* first = 0;
    TreeNode* second = 0;
    TreeNode* prev = 0;

    void inorder(TreeNode* root){
        if (root == NULL) return;
        //left
        inorder(root->left);

        //violating nodes detection
        if(prev != NULL && root->val < prev->val){
            if(first == NULL){
                first = prev;   //first violating node
                second = root;  //second violating node (might update) 
            }
            else{       //store and compute
                second = root;
            }
        }
        prev = root;

        //right
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {  //ATC and SC: O(n)
        inorder(root);
        //at this point i'll be having both violating nodes, so just swap them
        if(first != NULL && second != NULL){
            swap(first->val, second->val);
        }
    }
};