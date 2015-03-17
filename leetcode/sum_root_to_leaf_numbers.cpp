/**
https://leetcode.com/problems/sum-root-to-leaf-numbers/
    Depth first search
*/
/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int sumNumbers(TreeNode *root) {
            return sumTree(root,0);    
        }

        int sumTree(TreeNode *root,int baseSum){
            if(root == NULL) {
                return baseSum;
            } 

            baseSum = baseSum*10 + root->val;
            if(root->left == NULL && root->right == NULL) {
                return baseSum;
            }
            int curAns = 0;
            if(root->left != NULL) {
                curAns+=sumTree(root->left,baseSum);
            }

            if(root->right != NULL) {
                curAns+=sumTree(root->right,baseSum);
            }
            return curAns;
        }
};


