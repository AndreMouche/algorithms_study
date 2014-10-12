/**
 * https://oj.leetcode.com/problems/maximum-product-subarray/
 * dp[n][2]
 * dp[i][0]表示包含i在内的最小积
 * dp[i][1]表示包含i在内的最大积
 * 则：
 * dp[i][0] = min(dp[i-1][0]*A[i],dp[i-1][1]*A[i],A[i])
 * dp[i][1] = max(dp[i-1][0]*A[i],dp[i-1][1]*A[i],A[i])
 * O(n)
 */

#include <stdio.h>

class Solution {
    public:
        int maxProduct(int A[], int n) {
            if(n == 0) {
                return 0;
            }

            int ans = A[0];
            int max_product = A[0];
            int min_product = A[0];
            int i;
            for (i = 1; i < n; i ++) {
                int p1 = max_product * A[i];
                int p2 = min_product * A[i];
                max_product = A[i];
                min_product = A[i];
                if(max_product < p1) {
                    max_product = p1;
                } 
                if (max_product < p2) {
                    max_product = p2;
                }

                if (min_product > p1 ) {
                    min_product = p1;
                }

                if (min_product > p2) {
                    min_product = p2;
                }

                if (ans < max_product) {

                    ans = max_product;
                }


            }
            return ans;
        }
};

int main(){

    int n;
    int a[100];
    Solution solution = Solution();

    while(scanf("%d",&n)&& (n>0)) {
        int i;
        for(i = 0; i < n; i ++) {
            scanf("%d",&a[i]);
        }

        printf("%d\n",solution.maxProduct(a,n));



    }
}

