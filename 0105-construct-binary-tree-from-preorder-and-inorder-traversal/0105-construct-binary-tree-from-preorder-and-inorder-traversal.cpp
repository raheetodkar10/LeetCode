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
    int getIndex(int elem, vector<int>arr){
        for(int i=0;i<arr.size();i++){
            if(arr[i] == elem){
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int &preorderIndex, int inorderStart, int inorderEnd){  //&preorderIndex: coz without &, numbers repeat hot hote
        //base cases
        if(preorderIndex >= preorder.size()) return NULL;
        if(inorderStart > inorderEnd) return NULL;
        //preorder mdhla 1st elem fetch karaycha, that will be root. Apn fakt root insert karaych
        int elem = preorder[preorderIndex];
        preorderIndex++;
        //tya elem la node mdhe ghalaych
        TreeNode* root = new TreeNode(elem);
        //tya elem cha index inorder mde search karaycha
        int elemIndexInsideInorder = getIndex(elem,inorder);
        //rec ne left & right tree create karaychi
        root->left = buildTree(preorder,inorder,preorderIndex,inorderStart,elemIndexInsideInorder-1);  //changes in index for LS and RS 
        root->right = buildTree(preorder,inorder,preorderIndex,elemIndexInsideInorder+1,inorderEnd);
        return root;  //aplyala fakt root node return karaychay, logic of whole tree is already given above
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        TreeNode* root = buildTree(preorder,inorder,preorderIndex,inorderStart,inorderEnd);
        return root;
    }
};