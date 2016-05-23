public class Solution {
    /**
     * lose 4,8,12
     * win:5,6,7, 9, 10, 11
     */
    public boolean canWinNim(int n) {
        if(n%4==0){
            return false;
        }
        return true;
    }
}
