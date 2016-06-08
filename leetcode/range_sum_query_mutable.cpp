/**
 * https://leetcode.com/problems/word-ladder/
 * BFS 
 */
#include<stdio.h>
#include<unordered_set>
#include<map>
#include<string>
#include<iostream>
#include<queue>
using namespace std;
class NumArray {
public:
    NumArray(vector<int> &nums) {
        for(int i = 0; i < nums.length();i++) {
            if(i==0) {
                sums[i] = nums[i];
            } else {
                sums[i]+=nums[i];
            }
            cur_nums[i] = nums[i]
        }
    }

    void update(int i, int val) {
        
    }

    int sumRange(int i, int j) {
        
    }
    vector<int> cur_nums;
    vector<int> sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

int main() {
    int n;
    Solution so;
    while(scanf("%d",&n)!=EOF) {
        string start,end;
        cin>>start >> end;
        unordered_set<string> dict;
        string cur;
        while(n--) {
            cin >> cur;
            dict.insert(cur);
        }
        printf("%d\n",so.ladderLength(start,end,dict));
    }
}
