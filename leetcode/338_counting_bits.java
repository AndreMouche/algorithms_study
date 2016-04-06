
public class CountingBits {
    /**
     * [338. Counting Bits](https://leetcode.com/problems/counting-bits/)
     * 给一个数据n,求出0<=i<=num中i用二进制表示时1的个数
     * 规律题
     * 0
     * 进位
     * 1 
     * 进位后
     * 10 11
     * 再进位后
     * 100 101 110 111 
     * 。。即每次进位后的1的个数，都是前面所有小于它的数字的1个数加1.以此类推即可
     * @param num
     * @return
     */
    public static int[] countBits(int num) {
        if(num<0)return null;
        int[] ret = new int[num+1];
        ret[0]=0;
        int id = 1;
        int curlen =1;
        while(id<=num){
            for(int j=0;j<curlen && id<=num;j++,id++){
                ret[id]=ret[j]+1;
                
            }
            curlen = id;
        }
        
        return ret;
    }
    public static void main(String []args) {
       int[] ret = CountingBits.countBits(15);
       for(int id=0;id<=15;id++){
           System.out.println("id:"+id+" value:"+ret[id]);
       }
   }
}

