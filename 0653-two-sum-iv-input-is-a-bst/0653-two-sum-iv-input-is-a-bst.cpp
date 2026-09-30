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
    void storeInorder(TreeNode* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }
        //inorder:Left Root Right
        storeInorder(root->left,inorder);
        inorder.push_back(root->val);
        storeInorder(root->right,inorder);
    }

    bool checkTwoSum(vector<int>arr, int target){  //2 pointer approach
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s<e){
            int sum = arr[s] + arr[e];
            if(sum == target){
                return true;
            }
            if(sum > target){  //arr mde jr sum greater ala tr e mage ghyava lagnar 
                e--;
            }
            if(sum < target){
                s++;
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) { //inorder of BST is always sorted. Overall O(n)
    vector<int> inorder;
    storeInorder(root,inorder);  //inorder traversal store kela (O(n))
    bool ans = checkTwoSum(inorder,k);
    return ans;
    }
};