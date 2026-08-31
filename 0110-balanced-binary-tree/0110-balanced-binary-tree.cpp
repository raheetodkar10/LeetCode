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
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int ans = max(left,right) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {  //main 
        if(root==NULL) return true; //empty tree will be balanced
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        int absDiff = abs(leftHeight - rightHeight);
        if(absDiff > 1){  //not balanced
            return false;
        }
        else{
            //current node tr balance ahe evdh samajala, baki recursion
            //leftans
            bool leftAns = isBalanced(root->left);
            //rightans
            bool rightAns = isBalanced(root->right);
            if(leftAns == true && rightAns == true){  //ethe curr node true ahe ki nai he parat check karaychi garaj nai karn from 30 line we know ki curr balanced ahe
                return true;
            }
            else{
                return false;
            }
        }
    }
};