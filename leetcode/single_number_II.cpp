/**
 * https://oj.leetcode.com/problems/single-number-ii/
 * 数据列表中除了一个数字只出现过一次外，其余都出现过三次，求只出现过一次的那个数字。
 * 将数字转化为三进制对其后进行位运算加，各位对3取模即得答案。
 * 注意：
 * * 中间结果会越int界。
 * * 处理负数时，需将int转换为long long 后再转，否则会越界。nt型的-2147483648转为正数会造成越界
 * *  int 范围-2147483648~2147483647
 * 注意正负数转换时的越界问题：
 * 如int型的-2147483648转为正数会造成越界，需先转为long long 再转
 * int 范围-2147483648~2147483647
 * */
#include<stdio.h>
#include<iostream>
using namespace std;
class Solution {
    public:
        long long singleNumber(int A[], int n) {
            if(n<=0) {
                return 0;
            }
            int i;
            long long ans = 0;
            for(i=0;i<n;i++) {
                if(A[i]>=0) {
                    ans = ternary_and(ans,A[i]);
                }
            }

            if(ans > 0) {
                return ans;
            }

            for(i=0; i < n; i++) {
                if(A[i]<0) {
                    ans = ternary_and(ans,A[i]);
                }
            }
            return -((int)(ans));
        }

        long long ternary_and(long long a,long long b) {
            // cout << "ternary and a " << a << " b:" << b;
            a = a > 0?a:-a; //一定要在这里转，因为负的int在转为正的int时会越界！
            b = b > 0?b:-b;
            long long ans = 0;
            long long  base = 1;
            while(a|b) {
                int cur = (a%3 + b%3)%3;
                ans = ans+cur*base;
                base *= 3;
                a/=3;
                b/=3;
            }
            //cout << " ans: " << ans << endl;
            return ans;
        }
};

int main() {
   int a[100];
   Solution solution;
   int n;
   while(scanf("%d",&n) != EOF) {
       for(int i=0;i<n;i++){
           scanf("%d",&a[i]);
       }
       int ans = solution.singleNumber(a,n);
       cout << ans << endl;
   }
}
