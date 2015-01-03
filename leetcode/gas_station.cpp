/**
Gas Station https://oj.leetcode.com/problems/gas-station/
Description:
Find min{i},
make all sum[i][j] >= 0;
sum[i][j] = Sum(gas[i]-cost[i]+gas[i+1]-cost[i+1]....+gas[j]-cost[i]) 
j is i+1,i+2,i+3..n,0,1..i-1.

The start key is:

for each startid from 0 to n 
   compute each sum[start][j] until meet sum[start][j] < 0,
   if not ,return startid;
   else 
   next start should be j+1 as:
     sum[start+1][j] = sum[start][j]-(gas[start]-cost[start]) 
     gas[start]-cost[start] = sum[start][start+1] > 0
     =>sum[start+1][j] < sum[start][j] < 0
     =>min start should be j + 1


*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            for(int start=0;start<gas.size(); start ++) {
                int base = 0;
                int cur=start;
                do {
                    base += gas[cur] - cost[cur];
                    if(base < 0) {
                        break;
                    }
                    cur = (cur+1)%gas.size();
                } while(cur != start);

                if(base < 0) {
                    if(cur < start) {
                        return -1;
                    }
                    start = cur;
                    continue;
                }
                if(cur == start) {
                    return start;
                }
            }

            return -1;

        }
};

int main() {
    vector<int> gas;
    vector<int> cost;
    int n;
    Solution solution;
    while(scanf("%d",&n) != EOF) {
        gas.clear();
        cost.clear();
        for(int i = 0; i < n; i ++){
            int x;
            scanf("%d",&x);
            gas.push_back(x);
        }


        for(int i = 0; i < n; i ++){
            int x;
            scanf("%d",&x);
            cost.push_back(x);
        }

        printf("%d\n",solution.canCompleteCircuit(gas,cost));

    }
    return 0;
}
