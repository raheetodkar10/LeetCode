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
class Solution {   //best:O(log n), worst:O(n) for skew
public:
    int getMax(TreeNode* root){
        if(root == NULL){
            return -1;
        }
        while(root->right != NULL){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {  //first we'll search the key and then delete it
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            //if key matches then 4 cases:
            //delete node with:
            //1) 0 child
            if(root->left == NULL && root->right == NULL){
                TreeNode* temp = root;
                delete temp;
                return NULL;
            }
            //2) 1 child-left
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root;
                TreeNode* child = root->left;
                temp->left = NULL;  //node isolate karaychi
                delete temp;
                return child;
            }
            //3) 1 child-right
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root;
                TreeNode* child = root->right;
                temp->right = NULL;
                delete temp;
                return child;
            }
            //4) 2 child: here we'll take max val from LST. We can also take min val from RST
            if(root->left != NULL && root->right != NULL){
                //first we will replace the node to delete with max val in LST
                //after that we will call delete function on LST for replaced val
                //1st step: Replacement
                int replaceValue = getMax(root->left);
                root->val = replaceValue;
                //2nd step: Deletion
                root->left = deleteNode(root->left, replaceValue);
                return root;
            }
        }
        else{  //this is searching phase
            //key doesn't match
            if(key > root->val){
                //deletion right me hoga
                root->right = deleteNode(root->right, key);
            }
            else{
                //deletion left me hoga
                root->left =  deleteNode(root->left, key);
            }
        }
        return root;
    }
};