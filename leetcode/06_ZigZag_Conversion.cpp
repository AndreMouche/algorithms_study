
public class ZigZagConversion {
    /***https://leetcode.com/problems/zigzag-conversion/
     * 这题意也是理解了半天，醉得不要不要的。
     *  大概意思就是说，给你个字符串，转成z字写法，把重排后的字符串打印出来
     *  如给你｀0123456789｀
     *  转成1行：
     *  0123456789
     *  2行
     *  02468
     *  13579
     *  3行
     *  0 4 8
     *  13579
     *  2 6 
     *  4行
     *  0   6
     *  1  57
     *  2 4 8
     *  3   9
     *  以此类推
     *  
     *  解题：简单的字符串操作，简单推导后可得：
     *  每行中间那个字符编号为前一个加：2n-2-2id
     *  后面那个字符为2n-2
     *  以此类推即可
     * @param s
     * @param numRows
     * @return
     */
    public static String convert(String s, int numRows) {
        if(numRows <=1) {
            return s;
        }
       StringBuffer ans = new StringBuffer();
       int curDis = 2*numRows-2;
       for(int id=0;id<numRows;id++) {
           int cur=id;
           int midDis = curDis-2*id;
           while(cur<s.length()) {
               ans.append(s.charAt(cur));
               int mid = cur+midDis;
               cur += curDis;
               if(mid>=s.length()) {
                   break;
               }
               if(midDis == curDis) { //first line
                   continue;
               }
               
               if(midDis==0) { // last line
                   continue;
               }
               ans.append(s.charAt(mid));
               
           }
       }
       return ans.toString();
        
     }
    public static void main(String []args) {
         System.out.println(ZigZagConversion.convert("0123456789", 1));
         System.out.println(ZigZagConversion.convert("0123456789", 2));
         System.out.println(ZigZagConversion.convert("0123456789", 3));
         System.out.println(ZigZagConversion.convert("0123456789", 4));
     }
}

