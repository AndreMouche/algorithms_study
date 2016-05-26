public class Solution {
    public int removeElement(int[] nums, int val) {
       int ans = 0;
       for(int id=nums.length-1;id>=ans;id--){
           if(val == nums[id]){
              continue;
           } 
           
           while(ans<=id&&nums[ans]!=val){
               ans++;
           }
           if(ans>id)break;
           nums[ans]=nums[id];
           ans++;
       }
       return ans;
    }
}
