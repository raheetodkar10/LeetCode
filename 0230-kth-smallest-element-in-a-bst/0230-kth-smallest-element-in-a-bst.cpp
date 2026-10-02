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
    /*void solve(TreeNode* root, int k, int &count, TreeNode* &ans){  //2nd appr 0(n)
        if(root == NULL) return;
        //Left Root Right
        //Left
        solve(root->left, k, count, ans);
        //Root
        count++;
        if(count == k){
            ans = root;   //jr count==k tr ans mde tyala store karaych
        }
        //Right
        solve(root->right, k, count, ans);
    }*/

    void storeInorder(TreeNode* root, vector<int>& inorder){
        if(root == NULL) return;
        storeInorder(root->left, inorder);
        inorder.push_back(root->val);
        storeInorder(root->right, inorder);
    }

    int kthSmallest(TreeNode* root, int k) { //ya ques mde apn bst la inorder mde store karnar nd from that array k-1 th elem return karnar
        vector<int> inorder;
        storeInorder(root, inorder);
        return inorder[k-1];
        /*2nd appr:
        int count = 0;
        TreeNode* ans = NULL;
        solve(root, k, count, ans);
        return ans->val;*/
    }
};