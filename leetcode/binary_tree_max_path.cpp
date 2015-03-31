/**
 *https://leetcode.com/problems/binary-tree-maximum-path-sum/
 */
#include<stdio.h>

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
        int maxPathSum(TreeNode *root) {
            if(root == NULL) {
                return 0;
            }
            maxSum = root->val;
            int rootHalf = getMaxHalf(root);
            if(rootHalf>maxSum) {
                maxSum = rootHalf;
            }
            return maxSum;
        }

        int getMaxHalf(TreeNode *root) {
            int left = 0;
            int right = 0;
            if(root->left != NULL) {
                left = getMaxHalf(root->left);
            }

            if(root->right != NULL) {
                right = getMaxHalf(root->right);
            }

            int curSum = left+right + root->val;
            maxSum = maxSum > curSum ? maxSum : curSum;
            maxSum = maxSum > root->val ? maxSum:root->val;

            left += root->val;
            right += root->val;
            int curHalf = left > right?left:right;
            curHalf = curHalf > root->val?curHalf:root->val;
            maxSum = maxSum > curHalf ? maxSum:curHalf;
            return curHalf;
        }

        int maxSum;
};

int main() {

    return 0;
}
