/**
 *https://leetcode.com/problems/longest-consecutive-sequence/
 *uordered_set O(n)
 */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size() == 0) {
            return 0;
        }
        unordered_set<int> myset;
        for(int id = 0; id < num.size();id ++) {
            myset.insert(num[id]);
        }
        
        int ans = 0;
        for(int id = 0; id < num.size();id++) {
            int curv = num[id];
            int curAns = 1;
            myset.erase(curv);
            curv ++;
            while(myset.find(curv) != myset.end()) {
                myset.erase(curv);
                curAns ++;
                curv ++;
            }

            curv = num[id]-1;
            while(myset.find(curv) != myset.end()) {
                myset.erase(curv);
                curAns ++;
                curv --;
            }


            ans = ans > curAns?ans:curAns;    
        }       
        return ans;
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
