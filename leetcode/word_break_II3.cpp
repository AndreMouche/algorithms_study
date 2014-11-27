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
            check_tail(s,dict);
            return find(s,dict,"",0);
        }

        bool legallTail[10000];
        void check_tail(string s, unordered_set<string> &dict) {           
            int i,j;
            for(i=0;i<=s.length();i++) {
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

        }

        vector<string> find(string s,unordered_set<string> &dict,string commonPrefix,int rid) {
            int i,j;
            vector<string> ans;
            if(legallTail[rid] == false)
                return ans;

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
                    vector<string> cur_result = find(s.substr(i),dict,curComm,rid+i);
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
