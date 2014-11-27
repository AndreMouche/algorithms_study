/**
 * https://oj.leetcode.com/problems/word-break-ii/
 * DP
 * */
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
    public:
        vector<string> wordBreak(string s, unordered_set<string> &dict) {
            bool legallTail[10000];//legallTail[i] = true means s.sub(i) can be find in dict;
            vector<string> dp[10000];//dp[i] saves answers for s.sub(0,i+1);
            int i,j;
            for(i = 0; i < s.length(); i++) {
                dp[i].clear();
                legallTail[i] = false;
            }

            j=s.length()-1;
            for(i=j;i>=0;i--){
              string sstr = s.substr(i,j-i+1);
              if(dict.find(sstr) != dict.end()) {
                  legallTail[i] = true;
              }
            }

            for(j=s.length()-2;j>=0; j--) {
              if(legallTail[j+1] == false)
                  continue;
              for(i=j;i>=0;i--){
                 string sstr = s.substr(i,j-i+1);
                 if(dict.find(sstr) != dict.end() ) {
                    legallTail[i] = true;
                 }
              }
            }
            
            if(legallTail[0] == false) {
                return dp[0];
            }

            i = 0;
            for(j=0; j <s.length();j++){
               string sstr = s.substr(i,j-i+1);
               if(dict.find(sstr) != dict.end()) {
                  dp[j].push_back(sstr);
               }
            }

            for(i=1; i < s.length();i++) {
                if(dp[i-1].size()==0||legallTail[i]==false) {
                    continue;
                }
                for(j=i;j<s.length();j++) {
                    string sstr = s.substr(i,j-i+1);
                    if(dict.find(sstr) != dict.end()) {
                        for(int k=0; k < dp[i-1].size();k++) {
                           string cur_str=dp[i-1][k] + " " + sstr;
                           dp[j].push_back(cur_str);
                        }
                    }
                }
            }

            return dp[s.length()-1];
        }
};

int main() {
 unordered_set<string> dict;
/* dict.insert("a");
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
*/
 dict.insert("cat");
 dict.insert("cats");
 dict.insert("and");
 dict.insert("sand");
 dict.insert("dog");
 string test="catsanddog";
 Solution solution;
 vector<string> ans = solution.wordBreak(test,dict);
 for(int i = 0; i < ans.size(); i ++) {
     cout << ans[i] << endl;
 }
 return 0;
}
