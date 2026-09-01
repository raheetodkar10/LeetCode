/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {  //TC:O(n)
        if(root == NULL){
            return NULL;
        }
        if(root == p){
            return p;
        }
        if(root == q){
            return q;
        }
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        if(leftAns == NULL && rightAns == NULL){   //no p or q ans from LS or RS
            return NULL;
        }
        else if(leftAns != NULL && rightAns == NULL){
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }
        else{   //leftAns != NULL && rightAns != NULL , ethe left and right doni kdun ans alay, so that will be lca
            //current node ch LCA ahe   (nehmi top elem ch root nasnar, it will keep on changing as we go down the tree)
            return root;
        }
    }
};