public class Solution {
    public int climbStairs(int n) {
       int ans = 1;
       int num2=0;
       int num2_max=n/2;
       for(num2=1;num2<=num2_max;num2++){
           int num1=n-num2*2;
           ans+=this.compute(num1,num2);
       }
       return ans;
    }
    
    public int compute(int n2,int n1){
        if(n2==0||n1==0){
            return 1;
        }
        int total=n1+n2;
        int min=n1<n2?n1:n2;
        long ans = 1;
        for(int id=1;id<=min;id++){
            ans=ans*total/id;
            total--;
        }
        return (int)ans;
    }
}
