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
    vector<vector<int>> levelOrder(TreeNode* root) { //TC & SC:O(n)
        //empty tree
        if(root == NULL) return {};  //just return is also correct
        vector<vector<int>> ans;
        vector<int>currLevel;
        queue<TreeNode*> q;
        //initial state maintain karnyasathi:
        q.push(root);
        q.push(NULL);   //navin level indicate karnyasathi, null as marker

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL){
                //current level ki sari nodes print ho chuki hogi, go to next line
                ans.push_back(currLevel);
                currLevel.clear();   //used to empty the vector after we have stored the current level in ans ie apyala june level chya values nkoyt when we process the next level ie Empty it for next level
                //agar Q empty he, then do not insert null -> infinite loop mde adku shakto so
                //agar Q non empty he, then insert null -> to indicate rightmost node or end of level
                if(!q.empty()){  //jr Q empty nai, tr tyat pudchya level che sagle nodes ale astil -> tr te jithe samptil tithe mark karav lagnar
                    q.push(NULL);   //ie. jr Q empty ahe tr dont push NULL to avoid infinite loop
                }
            }
            else{
                currLevel.push_back(front->val);
                if(front->left!=NULL){   //left child
                    q.push(front->left);
                }
                if(front->right!=NULL){   //right child
                    q.push(front->right);
                }
            }
        } 
        return ans; 
    }
};
//NULL-> curr level che sagle nodes print zhalet & pudchya level che sagle nodes Q mde alet
/* only this much is also correct:
if(root == NULL) return {};  
queue<TreeNode*> q;
q.push(root);
q.push(NULL);  
while(!q.empty()){
    TreeNode* front = q.front();
    q.pop();
    if(front == NULL){
        cout<<endl;    
        if(!q.empty()){  
            q.push(NULL);  
        }
    }
    else{
        cout<<front->data<<" ";
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
            }
        }
    }
} */