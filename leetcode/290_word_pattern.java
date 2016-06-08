package leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class WordPattern_290 {
	 public boolean wordPattern(String pattern, String str) {
		 Map<String,Character> dict = new HashMap<String,Character>();
		 Set<Character> set = new HashSet<Character>();
		 String[] strs = str.split(" ");
		 if(pattern.length()!=strs.length) {
			 return false;
		 }
		 for (int id = 0;id<pattern.length();id++) {
			 String cur = strs[id];
			 char cur_char = pattern.charAt(id);

			 if(dict.containsKey(cur)) {
				 Character val = dict.get(cur);
				 if(val!=cur_char) {
					return false;
				 }
			 } else if(set.contains(cur_char)) {
				 return false;
			 } else {
				 dict.put(cur,cur_char);
				 set.add(cur_char);
			 }

		 }
	     return true;
	 }
}
