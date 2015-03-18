/**
 *https://leetcode.com/problems/longest-consecutive-sequence/
 */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size() == 0) {
            return 0;
        }
        map<int,bool> myset;
        for(int id = 0; id < num.size();id ++) {
            myset[num[id]] = true;
        }
        
        int reAns = 0;
        int ans = 0;
        map<int,bool>::iterator it;
        int last;
        for(it = myset.begin();it != myset.end();it++) {
            if(ans == 0 || it->first-1==last)  {
                ans ++;
                last = it->first;
//                printf("cur:%d\n",last);
            } else {
 //               printf("reAns:%d,ans:%d\n",reAns,ans);
                reAns = reAns > ans?reAns:ans;
                ans = 1;
                last = it->first;
            }
        }
        reAns = reAns > ans ? reAns:ans;
        return reAns;
    }
};

int main() {
    Solution so;
    int n;
    while(scanf("%d",&n) != EOF) {
       vector<int> num;
       for(int i=0; i < n; i++) {
          int x;
          scanf("%d",&x);
          num.push_back(x);
       }
       printf("%d\n",so.longestConsecutive(num));
    }
    return 0;
}
