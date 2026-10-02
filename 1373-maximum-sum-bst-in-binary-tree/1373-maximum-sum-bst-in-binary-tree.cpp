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
class Info{
    public:
        int minVal;
        int maxVal;
        int sum;
        bool isBST;
};

class Solution {
public:
    Info solve(TreeNode* root, int& sum){
        if(root == NULL){
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            return temp;
        }
        //we do left right and then root node
        Info leftAns = solve(root->left,sum);
        Info rightAns = solve(root->right,sum);
        //for node:
        Info currAns;
        currAns.minVal = min(root->val, min(leftAns.minVal,rightAns.minVal)); 
        currAns.maxVal = max(root->val, max(leftAns.maxVal,rightAns.maxVal)); 
        currAns.sum = root->val + leftAns.sum + rightAns.sum;
        //check whether its true or not
        if(root->val > leftAns.maxVal && root->val < rightAns.minVal && leftAns.isBST && rightAns.isBST){
            currAns.isBST = true;
            //agar ye ek valid BST ban gaya he, toh me sum ko update karne ka try kr leta hu
            sum = max(sum,currAns.sum);
        }
        else{
            currAns.isBST = false;
        }
        return currAns;
    }

    int maxSumBST(TreeNode* root) {
        int sum = 0;
        Info ans = solve(root,sum);
        return sum;
    }
};