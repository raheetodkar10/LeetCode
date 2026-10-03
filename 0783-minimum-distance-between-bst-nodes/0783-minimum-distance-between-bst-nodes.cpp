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
    void solve(TreeNode* root, TreeNode*& prev, int& ans){
        if(root == NULL) return;
        //inorder
        solve(root->left, prev, ans);

        if(prev != NULL){
            ans = min(ans, root->val - prev->val);  //we'll keep track of min diff bet root and prev and update min accordingly
        }
        //update prev to curr
        prev = root;

        solve(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {  //O(n)
        TreeNode* prev=0;
        int ans = INT_MAX;
        solve(root, prev, ans);
        return ans;
    }
};