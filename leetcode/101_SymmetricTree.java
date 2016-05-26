package leetcode;

public class SymmetricTree_101 {
     public boolean isSymmetric(TreeNode root) {
         if(root == null) {
             return true;
         }   
         return this.isSameTree(root.left, root.right);
     }
     public boolean isSameTree(TreeNode p,TreeNode q) {
         if(p==null && q==null) {
             return true;
         }
         if(p==null||q==null) {
             return false;
         }
         if(q.val!=p.val) {
             return false;
         }
         
         if(!this.isSameTree(p.left, q.right)) {
             return false;
         }
         if(!this.isSameTree(p.right, q.left)) {
             return false;
         }
         return true;
     }
}

