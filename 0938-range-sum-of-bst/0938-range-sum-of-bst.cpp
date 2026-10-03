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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        int currSum = 0;
        
        if(root->val >= low && root->val <= high){
            currSum += root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high); //we are pruning here, not travelling all nodes so complexity won't be in exponential
        }
        else if(root->val < low){
            currSum += rangeSumBST(root->right, low, high);
        }
        else{  //root->val > high
            currSum += rangeSumBST(root->left, low, high);
        }
        return currSum;
    }
};