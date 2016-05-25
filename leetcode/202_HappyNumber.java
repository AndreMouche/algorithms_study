public class Solution {
    public boolean isHappy(int n) {
           HashSet<Integer> set = new HashSet<Integer>(); 
           while(n!=1){
               if(set.contains(n)) {
                   return false;
               }
               set.add(n);
               int cur = 0;
               while(n>0){
                   int v=n%10;
                   n/=10;
                   cur=cur+v*v;
               }
               n=cur;
           }
           return true;
        }
}
