/***
https://oj.leetcode.com/problems/candy/
有n个小伙伴排成一列，每个小伙伴有一个评分，先给其发蛋糕，要求满足以下条件：
1）每人至少有一个蛋糕
2）评分较高的人所拥有的糖果数比其友邻大。
问：最少需要多少糖果给这些人？

DP,空间复杂度O(N)，时间复杂度O(N)
dp[i][0]表示第i左侧有多少数字是连续递减的,则
if(ratings[i]>ratings[i-1]) {
  dp[i][0] = dp[i-1]+1
}else {
  dp[i][0] = 0
}

同样的，dp[i][1]表示i右侧有多少数字连续递减的，则
if(ratings[i]>ratings[i+1]) {
  dp[i][1] = dp[i+1][1]+1
} else {
  dp[i][1] = 0;
}

那么每个位置的最小蛋糕数为ans[i] = max(dp[i][0],dp[i][1]) +1
证明：
假设r2<r3
那么dp[2][0] < dp[3][0]
dp[2][1] = 0,dp[3][0]>=0
最终r3的糖果数比r2多且只多一个
所有人的糖果数都符合这一规律，即所有人获得的都是最小值..
*/
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class  Solution {
    public:
        int candy(vector<int> &ratings) {
            vector<int>dp;
            int cur = 0;
            int i;
            dp.push_back(cur);
            for(i=1;i<ratings.size();i++) {
                if(ratings[i]>ratings[i-1]) {
                    cur +=1;
                } else {
                    cur = 0;
                }
                dp.push_back(cur);
            }

            cur = 0;

            for(i=ratings.size()-2;i>=0;i--) {
                if(ratings[i]>ratings[i+1]) {
                    cur += 1;
                } else {
                    cur = 0;
                }
                dp[i] = dp[i]>cur?dp[i]:cur;
            }

            int ans = ratings.size();
            for(i=0;i< ratings.size();i++) {
                ans+=dp[i];
            }
            return ans;
        }
};

int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0) {
        vector<int> num;
        int x;
        while(n--) {
            scanf("%d",&x);
            num.push_back(x);
        }
        Solution solution;
        cout << solution.candy(num) << endl;
    }
    return 0;
}
