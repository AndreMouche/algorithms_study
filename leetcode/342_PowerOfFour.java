public class Solution {
    public boolean isPowerOfFour(int num) {
        while(num>1&&num%4==0){
            num>>=2;
        }
        return num==1;
    }
}
