/**
 * https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
 * find the longest substring without repeating characters
 * hashmap,two point(left & right)
 */
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if(s.length() <= 1) {
             return s.length();
       }
       bool dp[300];
       memset(dp,false,sizeof(dp));
       int left = 0;
       int right = 0;
       dp[s.at(left)] = true;    

       int ans = 1;
       right ++ ;
       while(right < s.length()) {
           char rchar = s.at(right);
           while(dp[rchar]) {
              dp[s.at(left)] = false;
              left ++;       
           }
           dp[rchar] = true;
           int curans = right-left+1;
           if(curans > ans) {
              ans  = curans;
           }
           right ++;
       } 
       return ans;
    }
};

int main() {
 
    int n;
    Solution so;
    while(scanf("%d",&n)!=EOF) {
       string s;
       cin>>s;
       cout << "s:" << s << endl;
       cout << so.lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}
