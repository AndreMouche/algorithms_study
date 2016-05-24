package leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;

public class IntersectionOfTwoArraysII_350 {
     public int[] intersection(int[] nums1, int[] nums2) {
            HashMap<Integer,Integer> set = new HashMap<Integer,Integer>();
            for(int id=0;id<nums1.length;id++){
               if(set.containsKey(nums1[id])) {
                   set.put(nums1[id],set.get(nums1[id])+1);
               } else {
                   set.put(nums1[id],1);
               }
            }

            HashMap<Integer,Integer> anset = new HashMap<Integer,Integer>();
            int total = 0;
            for(int id=0;id<nums2.length;id++){
                if(set.containsKey(nums2[id]) && set.get(nums2[id])>0){
                    set.put(nums2[id],set.get(nums2[id])-1);
                    if(anset.containsKey(nums2[id])) {
                       anset.put(nums2[id],anset.get(nums2[id])+1);
                    } else {
                        anset.put(nums2[id],1);
                    }
                    
                    total++;
                }
            }

            int[] ans = new int[total];
            Iterator<Integer> it = anset.keySet().iterator();
            int id = 0;
            while(it.hasNext()) {
                int value = it.next();
                int cur = anset.get(value);
                while(cur>0) {
                    ans[id++] = value;
                    cur --;
                }
            }
            return ans;
        }

}

