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
    int maxDepth(TreeNode* root) {  //rec
        //base case: no tree
        if(root == NULL) return 0;
        int leftDepth = maxDepth(root->left) + 1;   //+1 of root node
        int rightDepth = maxDepth(root->right) + 1;
        int ans = max(leftDepth,rightDepth);
        return ans;
    }
};