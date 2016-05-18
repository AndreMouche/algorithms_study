import java.util.LinkedList;
import java.util.Queue;

/**
 * 求二叉树的深度，递归&非递归做法
 * @author wuxuelian
 *
 */
public class MaxDepthOfBinaryTree {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    /**
     * 非递归做法
     * @param root
     * @return
     */
    public int maxDepth1(TreeNode root) {
        if (root == null) {
            return 0;
        }
        root.val = 1;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        TreeNode last = root;
        while (!q.isEmpty()) {
            last = q.poll();
            if (last.left != null) {
                last.left.val = last.val + 1;
                q.add(last.left);
            }
            if (last.right != null) {
                last.right.val = last.val + 1;
                q.add(last.right);
            }
        }
        return last.val;
    }
    
    /**
     * 递归
     * @param root
     * @return
     */
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = this.maxDepth(root.left);
        int right = this.maxDepth(root.right);
        return left>right?left+1:right+1;
        
    }
}

