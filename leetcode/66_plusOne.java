package leetcode;

import java.util.ArrayList;
import java.util.Collections;

public class PlusOne_66 {
    public class Solution {
        public int[] plusOne(int[] digits) {
           ArrayList<Integer> ans = new ArrayList<Integer>();
           int left = 1;
           for(int id=digits.length-1;id>=0;id--){
               int cur = digits[id]+left;
               left = cur/10;
               cur = cur%10;
               ans.add(cur);
           }
           if(left>0) {
               ans.add(left);
           }
           
           int []cur_ans = new int[ans.size()];
           for(int id=ans.size()-1;id>=0;id--) {
              cur_ans[ans.size()-1-id] = ans.get(id);
           }
            return cur_ans;
       }
           
    }
}

