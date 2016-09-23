#include<stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
      //printf("%d\n",n);
      if(n<=1) {
        return 0;
      }
      if((n&1)==0) {
        return integerReplacement(n>>1)+1;
      }
      int plus = integerReplacement((n>>1)+1)+2; // 注意溢出
      int minus = integerReplacement(n-1)+1;
      return plus<minus?plus:minus;
    }
};
int main() {
    Solution s;
    printf("%d\n", s.integerReplacement(2147483647));
}
