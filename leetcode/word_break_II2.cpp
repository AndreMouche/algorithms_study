/**
 * https://oj.leetcode.com/problems/word-break-ii/
 * backtracking+dp
 * use dp check if answers exists quickily
 * */
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
    public:
        vector<string> wordBreak(string s, unordered_set<string> &dict) {
           return find(s,dict,"");
        }

        bool wordBreak1(string s, unordered_set<string> &dict) {           
            bool dp[10000];
            int i,j;
            for(i = 0; i <= s.length(); i++) {
                dp[i]=false;
            }

            dp[0] = true;
            for(i=1; i <= s.length();i++) {
                if(dp[i-1]==false) {
                    continue;
                }
                for(j=i;j<=s.length();j++) {
                    if(dict.find(s.substr(i-1,j-i+1)) != dict.end()) {
                        dp[j] = true;
                    }
                }

                if(dp[s.length()]) {
                    return true;
                }

            }

            return false;
        }

        vector<string> find(string s,unordered_set<string> &dict,string commonPrefix) {
            int i,j;
            vector<string> ans;
            if(wordBreak1(s,dict)== false) {
               return ans; 
            }
       
            if(commonPrefix.length() > 0) {
                commonPrefix+= " ";
            }
            for(i=1;i<=s.length();i++) {
                string cur = s.substr(0,i);
                if(dict.find(cur)!=dict.end()) {
                    string curComm = commonPrefix+cur;
                    if(i==s.length()) {


                        ans.push_back(curComm);
                        break;
                    }
                    vector<string> cur_result = find(s.substr(i),dict,curComm);
                    for(j=0;j<cur_result.size();j++) {
                        ans.push_back(cur_result[j]);
                    }
                }
            }

            return ans;
        }
};

int main() {
 unordered_set<string> dict;
 dict.insert("a");
 dict.insert("aa");
 dict.insert("aaa");

 dict.insert("aaaa");
 dict.insert("aaaaa");
 dict.insert("aaaaaa");
 dict.insert("aaaaaaa");
 dict.insert("aaaaaaaa");
 dict.insert("aaaaaaaaa");
 dict.insert("aaaaaaaaaa");
 //string test="aaaaaaab";
 string test="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
 Solution solution;
 solution.wordBreak(test,dict);
 return 0;
}
