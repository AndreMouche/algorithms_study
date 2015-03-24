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
class Solution {
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {

            int ans;
            unordered_set<string> curSet;
            ans = 1;
            curSet.insert(start);
            int slen = start.size();
            while(curSet.empty() != true) {
                unordered_set<string>::iterator it;
                unordered_set<string> nextSet;
                ans += 1;
                for(it = curSet.begin();it != curSet.end();it ++) {
                    string cur = *it;
                    for(int i = 0; i < slen;i++) {
                        string tmp = cur;
                        for(char c='a';c<='z';c++){
                            tmp[i] = c;
                            if(dict.find(tmp) != dict.end()) {
                                nextSet.insert(tmp);
                                dict.erase(tmp);
                            }
                            if(tmp == end) {
                                return ans;
                            }
                        }
                    }
                }

                curSet = nextSet;

            }

            return 0;
        }


};

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
