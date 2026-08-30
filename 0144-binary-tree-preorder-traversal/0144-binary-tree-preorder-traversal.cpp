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
    void solve(TreeNode* root,vector<int>& ans){  //preorder: Root Left Right , TC:O(n)
        //base case
        if(root == NULL){
            return;
        }
        //1 case: Root
        ans.push_back(root->val);  //ethe fakt 'root' nai lihu shakat
        //left
        solve(root->left,ans);
        //right
        solve(root->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);  //order of root & ans lakshat thev
        return ans;

        /*or (without vector ans)
        if(root == NULL) return;
        //1 case: Root
        cout<<root->val<<" ";
        //left
        preorderTraversal(root->left);
        //right
        preorderTraversal(root->right);
        */
    }
};