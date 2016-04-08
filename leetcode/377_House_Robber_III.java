/**
 * [337. House Robber III](https://leetcode.com/problems/house-robber-iii/)
 * @author wuxuelian
 *
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
    
    public void AddSon(Integer x,Integer y) {
        if(x== null) {
            this.left = null;
        } else {
            this.left = new TreeNode(x);
        }
        if(y== null) {
            this.right = null;
        } else {
            this.right = new TreeNode(y);
        }
    }
    
    TreeNode(Integer []value) {
        //TODO
    }
}

public class HouseRobberIII {

    public int rob(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int son_ans = 0; // 偷两个儿子时能获得的最大值
        int grand_sons = 0; // 跳过儿子能获得的最大值
        if (root.left != null) {
            son_ans += this.rob(root.left);
            grand_sons += root.left.val;
        }
        if (root.right != null) {
            son_ans += this.rob(root.right);
            grand_sons += root.right.val;
        }
        grand_sons += root.val; // 不偷儿子时，可偷当前节点
        root.val = son_ans; // 将偷儿子（ 即不偷当前节点）的最大值存在当前节点的value中以节省空间
        int cur_ans = grand_sons > son_ans ? grand_sons : son_ans;
        return cur_ans;
    }
    
    
    

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.AddSon(4, 5);
        root.left.AddSon(1, 3);
        root.right.AddSon(1, null);
        
        HouseRobberIII solu = new HouseRobberIII();
        System.out.println(solu.rob(root));
        
    }

}

