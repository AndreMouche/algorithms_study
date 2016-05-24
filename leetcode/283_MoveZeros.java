package leetcode;

/**
 * https://leetcode.com/problems/move-zeroes/
 * @author wuxuelian
 *
 */
public class MoveZeros_283 {
    public void moveZeroes(int[] nums) {
        int id = 0;
        int tid = 0;
        while(id<nums.length){
            while(id<nums.length&&nums[id]==0) {
                id++;
            }
            if(id>=nums.length)break;
            nums[tid++]=nums[id++];
        }
        while(tid<nums.length){
            nums[tid++]=0;
        }
    }
    
    public static void main(String []args){
        MoveZeros_283 s = new MoveZeros_283();
        int[] data =new int[]{1,2,0,0,3,0,4,0,0};
        s.moveZeroes(data);
        System.out.println(data.toString());
    }
}

