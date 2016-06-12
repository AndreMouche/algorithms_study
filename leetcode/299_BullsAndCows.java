package leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * https://leetcode.com/problems/bulls-and-cows/
 * @author wuxuelian
 *
 */
public class BullAndCows_299 {
	   public String getHint(String secret, String guess) {
	       Map<Character, Integer> sMap = new HashMap<Character, Integer>();
	       int id = 0;
	       for(id = 0; id<secret.length();id++) {
	    	   if(id<guess.length() && secret.charAt(id) == guess.charAt(id)) {
	    		    continue;
	    	   }

	    	   char sChar = secret.charAt(id);
	    	   if(sMap.containsKey(sChar)) {
	    		   sMap.put(sChar, sMap.get(sChar)+1);
	    	   } else {
	    		   sMap.put(sChar, 1);
	    	   }
	       }

	       int b = 0;
	       int a = 0;
	       for(id=0;id<guess.length();id++) {
	    	   if(id<secret.length() && secret.charAt(id) == guess.charAt(id)) {
	    		    a++;
	    		    continue;
	    	   }

	    	   char gChar = guess.charAt(id);
	    	   if(sMap.containsKey(gChar) && sMap.get(gChar) > 0) {
	    		   b++;
	    		   sMap.put(gChar, sMap.get(gChar)-1);
	    	   }

	       }

	       return String.format("%dA%dB", a,b);
	    }

	   public static void main(String []args){
		   BullAndCows_299 s = new BullAndCows_299();
		   System.out.println(s.getHint("1432","1234"));
		   System.out.println(s.getHint("1807","7810"));
		   System.out.println(s.getHint("1123","0111"));
		   System.out.println(s.getHint("1123","011123"));
	   }
}
