public class Solution {
    public int rob(int[] nums) {
        int ppre = 0;
        int pre = 0;
        for(int id=0;id<nums.length;id++){
            int cur=(ppre+nums[id])>pre?(ppre+nums[id]):pre;
            ppre=pre;
            pre=cur;
        }
        return pre;
    }
}
