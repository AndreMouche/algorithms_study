/**
 * https://oj.leetcode.com/problems/palindrome-partitioning-ii/
 * dp O(n*n)
 */
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int minCut(string s) {
            int n = s.length();
            // isPa[i][j] = true when substr[i,j] is a palindrome
            vector< vector < bool > > isPa(n + 1, vector<bool>(n + 1, false));;
            // dp[i] is minCut for str[0,i]
            vector<int> dp;
            for(int right = 0; right < n; right++) {
                dp.push_back(right);
            }

            for(int right = 1; right < n; right ++) {
                char rchar = s.at(right);
                for(int left = right; left >= 0; left --) {
                    char lchar = s.at(left);
                    if(lchar == rchar && (right-left <= 2 || isPa[left+1][right-1])){
                        isPa[left][right] = true;
                        int curCut = 0;
                        if(left > 0) {
                            curCut = dp[left-1] + 1;
                        }

                        if(curCut < dp[right]) {
                            dp[right] = curCut;
                        }

                    }

                }
            }
            return dp[n-1];
        }

};

int main() {
    int n;
    Solution solution;
    while(scanf("%d",&n)!=EOF) {
        string s;
        cin >> s;

        cout << "origin:" << s << endl;
        //continue;
        cout << "minCut:" << solution.minCut(s) << endl;
    }
    return 0;
}
