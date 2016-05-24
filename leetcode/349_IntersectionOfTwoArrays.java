public class Solution {
  public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set = new HashSet<Integer>();
        for(int id=0;id<nums1.length;id++){
            set.add(nums1[id]);
        }

        HashSet<Integer> anset = new HashSet<Integer>();
        for(int id=0;id<nums2.length;id++){
            if(set.contains(nums2[id])) {
                anset.add(nums2[id]);
            }
        }

        int[] ans = new int[anset.size()];
        Iterator<Integer> it = anset.iterator();
        int id = 0;
        while(it.hasNext()) {
            ans[id++] = it.next();
        }
        return ans;
    }
}
