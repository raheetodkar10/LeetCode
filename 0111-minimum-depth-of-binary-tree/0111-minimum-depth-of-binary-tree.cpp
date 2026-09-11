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
    int minDepth(TreeNode* root) {
        //base case
        if(root == NULL) return 0;
        //aplyala null cases separately handle karave lagnar ie skew tree (jr right tree nasel, tr it will return 0 instead of the depth of left tree, which is wrong)
        if(root->left == NULL){
            return minDepth(root->right) + 1;
        }
        if(root->right == NULL){
            return minDepth(root->left) + 1;
        }

        int leftDept = minDepth(root->left) + 1;
        int rightDept = minDepth(root->right) + 1;
        int ans = min(leftDept,rightDept);
        return ans;
    }
};