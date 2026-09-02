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
    int getIndex(int elem, vector<int> arr){
        for(int i=0;i<arr.size();i++){
            if(arr[i] == elem){
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int &postorderIndex){
        //base cases
        if(postorderIndex < 0) return NULL;
        if(inorderStart > inorderEnd) return NULL;

        int elem = postorder[postorderIndex];
        postorderIndex--;   //from right to left

        TreeNode* root = new TreeNode(elem);
        int elemIndexInsideInorder = getIndex(elem,inorder);

        //postorder mde: Left Right Root, so jevha apn root create karto mg tya nantr adhi RS create karaycha mg LS(right to left)   ***This is IMP
        root->right = buildTree(inorder,postorder,elemIndexInsideInorder+1,inorderEnd,postorderIndex); 
        root->left = buildTree(inorder,postorder,inorderStart,elemIndexInsideInorder-1,postorderIndex); 
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {  //TC:O(n^2)
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        int postorderIndex = postorder.size()-1;
        TreeNode* root = buildTree(inorder,postorder,inorderStart,inorderEnd,postorderIndex);
        return root;
    }
};