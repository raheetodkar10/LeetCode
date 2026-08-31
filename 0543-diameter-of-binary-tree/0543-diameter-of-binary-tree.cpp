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
    int height(TreeNode* root){  //same code as of max depth
        if(root==NULL) return 0;
        int left = height(root->left) + 1;
        int right = height(root->right) + 1;
        int ans = max(left,right);
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;  //base case
        int poss1 = height(root->left) + height(root->right);   //nusta left right lihu nkos
        int poss2 = diameterOfBinaryTree(root->left);  //LS
        int poss3 = diameterOfBinaryTree(root->right); //RS
        int ans = max(poss1,max(poss2,poss3));
        return ans; 
    }
};