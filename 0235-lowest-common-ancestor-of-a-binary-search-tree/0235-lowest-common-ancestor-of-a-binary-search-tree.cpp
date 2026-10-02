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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        //case 1: p,q in LST: neglect RST and select left side
        if(p->val < root->val && q->val < root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            if(leftAns != NULL){  //if leftAns is valid
                return leftAns;
            }
        }
        //case 2: p,q in RST: neglect LST and select right side
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            if(rightAns != NULL){
                return rightAns;
            }
        }
        //case 3: p in LST, q in RST: LCA is root
        //case 4: p in RST, q in RST: LCA is root
        return root;
    }
};

/*2nd appr:
        if(root == NULL){
            return NULL;
        }
        if(root->val == p->val){
            return p;
        }
        if(root->val == q->val){
            return q;
        }
        //ethe alo mhanje we didn't get p and q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //4 cases
        if(left == NULL && right == NULL){
            return NULL;
        }
        else if(left != NULL && right == NULL){
            return left;
        }
        else if(left == NULL && right != NULL){
            return right;
        }
        else{   //(left != NULL && right != NULL)
            return root;*/