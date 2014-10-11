/**
 * https://oj.leetcode.com/problems/maximum-product-subarray/
 * 以0为分界点，将列表分成若干的子串分而治之：
 * 各个子串结果互不干涉，取出子串中最大那个结果即可。
 * 对于各个子串：
 * 1.算出该子串包含的负数个数，若为偶数，直接返回子串所有项乘积即可
 * 2.若子串负数个数为奇数，则找出子串两端的那两个负数对应的游标left,right
 * 那么该子串的最大值为max(product(..,a[right-1]),product(a[left+1],..));
 *
 * 当所有子串结果为负数：
 * 判断0是否在数组中，若存在，则返回0；
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
            int i = 0;
            bool mark_zero = false;
            while(i < n && A[i] == 0) {
                mark_zero = true;
                i ++;

            }

            while(i < n) {
                int cur_product = 0;
                if(A[i] > 0) {
                    cur_product = 1;
                    while(i<n&&A[i]>0){
                        cur_product *= A[i];
                        i ++;
                    }
                    if(i == n || A[i] == 0 ) {
                        if(cur_product > ans) {
                            ans = cur_product;
                        }

                        while(i<n&&A[i] == 0) {
                            mark_zero = true;
                            i ++;
                        }
                        continue;
                    }
                }

                int left = i;
                int right = i;
                int na_num = 0;
                while(i<n && A[i] != 0) {
                    if (A[i] < 0 ) {
                        na_num += 1;
                        right = i;
                    }
                    i ++;
                }

                if(left+1 == i){
                    if(cur_product == 0){
                        cur_product = A[left];
                    }
                } else {
                    if(cur_product == 0) {
                        cur_product = 1;
                    }
                    int j;
                    int left_product = 1;
                    for(j = left;j < right;j++){
                        left_product*=A[j];
                    }

                    int right_product = 1;
                    for(j = right; j < i; j ++){
                        right_product *= A[j];
                    }

                    if(na_num%2 == 0) {
                        cur_product  *= left_product*right_product;
                    }else {
                        int real_left = left_product*cur_product;//(..,A[right-1)
                        int real_right = right_product*left_product/A[left]; //(A[left+1],A[i])
                        cur_product = real_left;
                        if(cur_product < real_right) {
                            cur_product = real_right;
                        }
                    }
                }
                if(cur_product > ans) {
                    ans = cur_product;
                }

                while(i<n&&A[i] == 0) {
                    i ++;
                    mark_zero = true;
                }           
            }

            if(ans < 0 && mark_zero) {
                ans = 0;
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

