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
    void solve(TreeNode* root, int target, int sum, vector<int> temp, vector<vector<int>> &ans){
        if(root == NULL) return;
        //curr node pr
        sum = sum + root->val;
        temp.push_back(root->val);

        //leaf node
        if(root->left == NULL && root->right == NULL){
            if(sum == target){
                ans.push_back(temp);
                //return;
            }
        }
        //baki rec
        solve(root->left,target,sum,temp,ans);  //LS
        solve(root->right,target,sum,temp,ans); //RS

        //jr fakt 'temp' pass kelay ie pass by value kelay, so this is optional. 
        //but if '&temp'ie pass by reference, then it is compulsory  
        //temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        vector<vector<int>> ans;
        solve(root,targetSum,sum,temp,ans);
        return ans;
    }
};