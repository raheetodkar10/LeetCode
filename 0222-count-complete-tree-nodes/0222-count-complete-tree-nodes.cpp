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
    int findLeftHeight(TreeNode* root){
        int h=0;
        while(root != NULL){
            h++;
            root = root->left;
        }
        return h;
    }
    int findRightHeight(TreeNode* root){
        int h=0;
        while(root != NULL){
            h++;
            root = root->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh =  findLeftHeight(root);
        int rh =  findRightHeight(root);

        if(lh == rh){
            //FCBT
            return (1<<lh) - 1;  //means: 2^n-1
        }
        else{  //lh != rh
            int leftCount = countNodes(root->left);
            int rightCount = countNodes(root->right);
            return leftCount + rightCount + 1;
        }
        
    }
};