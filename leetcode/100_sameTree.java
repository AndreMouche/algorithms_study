/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null||q==null){
            return (q==null&p==null);
        }
        
        if(q.val != p.val) {
            return false;
            
        }
        
        return this.isSameTree(p.left,q.left) && this.isSameTree(p.right,q.right);
        
    }
}
