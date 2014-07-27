/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
       vector<int> leftp;
       vector<int> rightp;
       vector<int> result;
       if(root == NULL) {
           return result;
       }
       if(root->left!=NULL) {
           leftp = postorderTraversal(root->left);
       }
       
       if(root->right!=NULL){
           rightp = postorderTraversal(root->right); 
       }
       
       
       for(int i=0;i<rightp.size();i++){
           leftp.push_back(rightp[i]);
       }
       leftp.push_back(root->val);
       return leftp;
    }
};
