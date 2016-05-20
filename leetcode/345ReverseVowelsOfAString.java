import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode.com/problems/reverse-vowels-of-a-string/
 * 模拟题，简单
 * @author wuxuelian
 *
 */
public class ReverseVowelsOfAString345 {

    public String reverseVowels(String s) {

        List<Integer> indexes = new ArrayList<Integer>();
        String tmp = s.toLowerCase();
        for (int id = 0; id < s.length(); id++) {
            char cur = tmp.charAt(id);
            if (cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o'
                    || cur == 'u') {
                indexes.add(id);
            }
        }
        StringBuffer ans = new StringBuffer(s);
        int total = indexes.size();
        int mid = total >> 1;
        for (int id = 0; id < mid; id++) {
            int left = indexes.get(id);
            int right = indexes.get(total - id - 1);
            ans.setCharAt(left, s.charAt(right));
            ans.setCharAt(right, s.charAt(left));
        }
        return ans.toString();
    }

    public static void main(String[] args) {
        ReverseVowelsOfAString345 s = new ReverseVowelsOfAString345();
        String[] words = { "What", "must", "be", "shall", "be." };
        for (int id = 0; id < words.length; id++) {
            System.out.println(words[id] + " reverse:"
                    + s.reverseVowels(words[id]));
        }
    }

}

