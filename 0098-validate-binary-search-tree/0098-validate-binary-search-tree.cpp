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
    bool solve(TreeNode* root, long long lb, long long rb){
        if(root == NULL) return true;
        bool isCurrentNodeOk = root->val > lb && root->val < rb;
        bool leftAns = solve(root->left, lb, root->val);  //jeva left la janar tevha right side chi val update honar
        bool rightAns = solve(root->right, root->val, rb);
        return isCurrentNodeOk && leftAns && rightAns;

        /*instead of above 4 lines:
        return (root->val > lb && root->val < rb) && solve(root->left, lb, root->val) && solve(root->right, root->val, rb); */
    }

    bool isValidBST(TreeNode* root) {  //TC & SC: O(n)
        long long lb = LONG_MIN;   //left boundary(lower) (INT_MIN pn use kru shakto but it gives error for long ans so)
        long long rb = LONG_MAX;   //right boundary(upper)
        //INT_MIN < root < INT_MAX  is done above
        return solve(root,lb,rb);
    }
};