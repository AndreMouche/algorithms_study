package leetcode;

public class ReverseBits_190 {
    
    /**
     * https://leetcode.com/problems/reverse-bits/
     * @param n
     * @return
     */
    public int reverseBits(int n) {
        long ans = (long) 0;
        for(int id=0;id<32;id++){
            ans=(ans<<1)+(n&1);
            n=n>>1;
        }
        return (int)ans;
    }
    
    public static void main(String []args){
        ReverseBits_190 r = new ReverseBits_190();
        System.out.println(r.reverseBits(1<<31));
        System.out.println();
        System.out.println((-0) & 1);
    }
    
}

