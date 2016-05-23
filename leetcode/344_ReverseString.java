package leetcode;

/**
 * https://leetcode.com/problems/reverse-string/
 * @author wuxuelian
 *
 */
public class ReverseString344 {
    public String reverseString(String s) {
        StringBuffer ans = new StringBuffer();
        for(int id=s.length()-1;id>=0;id--){
            ans.append(s.charAt(id));
        }
        return ans.toString();
    }
}

