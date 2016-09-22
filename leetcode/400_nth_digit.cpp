#include<stdio.h>

// 计算level位数的第一个数字
class Solution {
public:
     // 计算level位数的第一个数字
    int computeDigitStart(int level) {
        int start = 1;
        while(level>1) {
          start *= 10;
          level--;
        }
        return start;
    }
    //计算出level位数一共有的数字数,long型考虑越界
    long computeNum(int level) {
       long ans = level*9;
       while(level>1) {
         ans*=10;
         level--;
       }
       return ans;
    }


    int findNthDigit(int n) {
      if(n<=9) {
        return n;
      }
      //printf("compute %d\n",n);
       int digit = 1;
       long digNumber = computeNum(digit);
       while(digNumber<=n) {
         n-=digNumber;
         digit ++;
         digNumber=computeNum(digit);
       }
       int pos = (n+digit-1)/digit; //是digit的第pos位数字
       int posInNumber = digit-n%digit+1; // 是该数字从0开始的第几位上的数字
       if(n%digit==0) {  // 若能整除，则最后一位为需要的数字
         posInNumber=0;
       }
       int number = pos+computeDigitStart(digit)-1; //定位到具体数字
       //printf("n=%d,digit=%d,number=%d,posInNumber=%d number/compute=%d\n",number,digit,n,posInNumber,computeDigitStart(posInNumber));
       number/=computeDigitStart(posInNumber);
       return number%10;
    }

};



int main(){
  Solution s;
  printf("%d\n",s.findNthDigit(1));
  printf("%d\n",s.findNthDigit(190));
  printf("%d\n",s.findNthDigit(191));
  printf("%d\n",s.findNthDigit(89));
  printf("%d\n",s.findNthDigit(199));
  printf("%d\n",s.findNthDigit(305));
  printf("%d\n",s.findNthDigit(1000000000));
}
