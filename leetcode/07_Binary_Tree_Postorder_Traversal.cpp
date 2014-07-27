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
        vector<TreeNode *> mystack;
        vector<int> result;
        if(root==NULL){
            return result;
        }
        
        TreeNode *curNode = root;
        TreeNode *preNode = NULL;
        mystack.push_back(curNode);
        while(mystack.size()!=0){
            curNode = mystack.back();
            
            if(preNode==NULL || preNode->left == curNode || preNode->right == curNode) { // process sons
                if(curNode->left==NULL && curNode->right==NULL) {
                    result.push_back(curNode->val);
                    preNode = curNode;
                    mystack.pop_back();
                    continue;
                }
                
                if(curNode->left != NULL) {
                    mystack.push_back(curNode->left);
                    preNode = curNode;
                    continue;
                }
                
                if(curNode->right != NULL) {
                    mystack.push_back(curNode->right);
                    preNode = curNode;
                    continue;
                }
            }
            
            if(curNode->left == preNode) {
                    if(curNode->right==NULL) {
                        result.push_back(curNode->val);
                        preNode = curNode;
                        mystack.pop_back();
                        continue;
                    }
                    mystack.push_back(curNode->right);
                    preNode = curNode;
                    continue;  
            }
            
            if(curNode->right==preNode) {
                result.push_back(curNode->val);
                preNode = curNode;
                mystack.pop_back();
                continue;
            }
            
        }
        return result;
        
    }
};
