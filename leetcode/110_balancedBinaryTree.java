package leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class BalanceBinaryTree_110 {
    /**
     * Definition for a binary tree node.
     * */
    public class TreeNode {
          int val;
          TreeNode left;
          TreeNode right;
          TreeNode(int x) { val = x; }
    }
    public class Solution {
        public boolean isBalanced(TreeNode root) {
            if(root==null) {
                return true;
            }
            
            int left = 0;
            int right = 0;
            if(root.left!=null) {
                if(!this.isBalanced(root.left)) {
                  return false;
                }
                left = root.left.val;
            }
            if(root.right!=null) {
                if(!this.isBalanced(root.right)) {
                    return false;
                }
                right = root.right.val;
            }
            
            if(Math.abs(left-right)>1){
                return false;
            }
            
            root.val=Math.max(left, right)+1;
            return true;
        }
    }
}

