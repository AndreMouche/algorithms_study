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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        List<Integer> cur_level = new ArrayList<Integer>();
        if(root!=null){
            queue.add(root);
            cur_level.add(root.val);
            root.val=0;
        }
        
        while(!queue.isEmpty()){
            TreeNode curNode = queue.poll();
            int level_val=curNode.val+1;
            
            if(level_val>ans.size()) {
                ans.add(cur_level);
                cur_level = new ArrayList<Integer>();
            }
            if(curNode.left!=null){
                cur_level.add(curNode.left.val);
                curNode.left.val = level_val;
                queue.add(curNode.left);
            }
            
            if(curNode.right!=null){
                cur_level.add(curNode.right.val);
                curNode.right.val = level_val;
                queue.add(curNode.right);
            }
        }  
       Collections.reverse(ans);
       return ans;
    }
}
