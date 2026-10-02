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
    TreeNode* solve(vector<int>& inorder, int start, int end){
        if(start > end){
            return NULL;
        } 
        int mid = (start+end)/2;
        int elem = inorder[mid];
        TreeNode* root = new TreeNode(elem);
        //1 case mei, baki rec
        root->left = solve(inorder, start, mid-1);
        root->right = solve(inorder, mid+1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {  //height balanced so can safely use mid, jr height balanced nasta tr randomly choose any node as root & multiple bst can exist
    int start=0;
    int end=nums.size()-1;
    TreeNode* root = solve(nums, start, end);
    return root;
    }
};