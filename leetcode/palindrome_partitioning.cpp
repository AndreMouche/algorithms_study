/**
 * https://oj.leetcode.com/problems/palindrome-partitioning/
 * backtracking
 */
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalinDrome(string s) {
        int left,right;
        left = 0;
        right = s.length() - 1;
        while(left<=right) {
           if(s.at(left) != s.at(right)) {
                return false;
           }
           left ++;
           right --;
        }
        return true;
    }
    vector<vector <string> > partition(string s) { 
 //       cout << "cur s:" << s << endl;
        vector<vector <string> > ans;
        if(isPalinDrome(s)) {
            vector<string> curAns;
            curAns.push_back(s);
            ans.push_back(curAns);
        }

        for(int id = s.length() - 1; id > 0; id --) {
            string tail = s.substr(id);
            if(isPalinDrome(tail)) { 
                string prefix = s.substr(0,id);
   //             cout << "prefix " << prefix << " tail:" << tail << endl;
                vector < vector<string> > subAns = partition(prefix);
                for(int j = 0; j < subAns.size(); j ++) {
                    subAns[j].push_back(tail);
                    ans.push_back(subAns[j]);
                }
                
            }   
        }

        return ans;
    }
};

int main() {
   int n;
   Solution solution;
   while(scanf("%d",&n)!=EOF) {
     string s;
     cin >> s;

     cout << "origin:" << s;
     cout << "sub str[1+]:" << s.substr(1) << endl;
     cout << "sub str[0,1]:" << s.substr(0,1) << endl;
     //continue;
     vector < vector<string> > ans = solution.partition(s);
     for(int i = 0; i < ans.size(); i ++) {
         for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ",";
         }
         cout << endl;
     }
   }
   return 0;
}
