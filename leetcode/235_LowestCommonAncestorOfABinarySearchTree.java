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
      public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
             if(root==null){
                 return null;
             }
             if(p==null){
                 return q;
             }
             
             if(q==null){
                 return p;
             }
             
             ArrayList<TreeNode> pNodes = this.findNode(root, p);
             ArrayList<TreeNode> qNodes = this.findNode(root, q);
             
             if(qNodes==null||pNodes==null) {
                 return null;
             }
             
             int count = qNodes.size()<pNodes.size()? qNodes.size():pNodes.size();
             int id = 0;
             while(id<count&&pNodes.get(id)==qNodes.get(id)) {
                 id ++;
             }
             
             if(id==0)return null;
             return pNodes.get(id-1);
        }
        
        public ArrayList<TreeNode> findNode(TreeNode root,TreeNode p){
            ArrayList<TreeNode> ans = new ArrayList<TreeNode>();
            if(root == null){
                return null;
            }
            ans.add(root);
            if(root==p){
                return ans;
            }
            
            if(root.left != null) {
                ArrayList<TreeNode> tmp = this.findNode(root.left, p);
                if(tmp!=null) {
                    ans.addAll(tmp);
                    return ans;
                }
            }
            
            if(root.right != null) {
                ArrayList<TreeNode> tmp = this.findNode(root.right, p);
                if(tmp!=null) {
                    ans.addAll(tmp);
                    return ans;
                }
            }
            return null;
        }
}
