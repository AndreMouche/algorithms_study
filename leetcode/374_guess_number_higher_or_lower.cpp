#include<stdio.h>
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num) {
  if(num<1702766719){
    return 1;
  }else if (num>1702766719) {
    return -1;
  }
  return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int left=1;
        int right=n;
        while(left<=right) {
            int mid=(left>>1)+(right>>1)+(left&right&1);
            int gs=guess(mid);
            //printf("left=%d,right=%d,mid=%d gs=%d\n", left,right,mid,gs);
            if(gs==0) {
                return mid;
            }
            if(gs<0) {
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return right;
    }
};

int main(){
    Solution s;
    printf("%d\n",s.guessNumber(2126753390));
}
