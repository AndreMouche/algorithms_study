#include<iostream>
#include<stdio.h>
class Solution {
public:
    int getSum(int a, int b) {
      //printf("a=%d,b=%d\n",a,b);
      int ans = 0;
      int pre =0;
      for(int id=0;id<=32;id++,a=a>>1,b=b>>1) {
          //printf("a=%d,b=%d,pre=%d,ans=%d\n",a,b,pre,ans);
          if(ans<0) { //如果答案已计算到负数标识位，则不需要再往下计算
            return ans;
          }
          if(a&b&1||b&pre&1||a&pre&1) { //当前位有两个及以上1时，需要进位
             ans=ans|(((a^b^pre)&1)<<id);
             pre=1;
             continue;
          }
          ans = ans|(((a|b|pre)&1)<<id); //当前位1个及以下1时，不需要进位
          pre = 0;
      }
      return ans;
    }
};



int main(){
  Solution s ;
  printf("%d\n", s.getSum(-12,-8));//20
  printf("%d\n", s.getSum(1,2));//3
  printf("%d\n", s.getSum(5,2));//7
  printf("%d\n", s.getSum(5,9));//14
  printf("%d\n", s.getSum(11,12));//23
  printf("%d\n", s.getSum(-1,2));//1
  printf("%d\n", s.getSum(-1,12));//11
  printf("%d\n", s.getSum(-1,-12));//-13
  printf("%d\n", s.getSum(5,-12));//-7
  printf("%d\n", s.getSum(2147483647,-2147483648));//-7

}
