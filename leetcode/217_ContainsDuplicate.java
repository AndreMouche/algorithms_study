public class Solution {
      public boolean containsDuplicate(int[] nums) {
            HashSet<Integer> set = new HashSet<Integer>();
            for(int id=0;id<nums.length;id++){
                if(set.contains(nums[id])){
                    return true;
                }
                set.add(nums[id]);
            }
            return false;
        }
}
