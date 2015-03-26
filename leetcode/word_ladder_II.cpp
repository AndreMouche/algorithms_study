/**
 * https://leetcode.com/problems/word-ladder-ii/
 * BFS & backtracking 
 * Similiar with word-ladderI
 */
/*
 5
 hit
 cog
 hot
 dot
 dog
 lot
 log
 */
#include<stdio.h>
#include<unordered_set>
#include<map>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<vector <string> > findLadders(string start, string end, unordered_set<string> &dict) {
            unordered_set<string>starts;
            starts.insert(start);
            dict.insert(end);
            return findAns(starts,end,dict);
        }

        /** find ans for each word in starts group as start string 
         * @param starts,a group of word,
         * @param end,end string 
         * @param dict 
         */
        vector<vector <string> > findAns(unordered_set<string> starts,string end,unordered_set<string>&dict) {
            vector<vector <string> > curAns;
            if(dict.size() ==0 || starts.size() == 0) {
                return curAns;
            }
            unordered_set<string>::iterator it;
            map<string, vector<string> > cur_pre; 
            unordered_set<string> nexts;
            for(it = starts.begin();it != starts.end();it ++) {// for each string in start,find next on in dict 
                string cur = *it;
                int slen = cur.size();
                for(int i = 0; i < slen; i ++) {
                    for(char c='a';c <='z';c++) {
                        string tmp = cur;
                        tmp[i] = c;
                        if(dict.find(tmp) != dict.end() || tmp == end){
                            cur_pre[tmp].push_back(cur); //mark current word related to start word  
                            nexts.insert(tmp); //insert current to  start word set on next step
                        } 
                    }
                }
            }

            if(cur_pre[end].size() != 0) { // if end finded,return 
                for(int i = 0; i < cur_pre[end].size();i++) {
                    vector<string> onAns;
                    onAns.push_back(cur_pre[end][i]);
                    onAns.push_back(end);
                    curAns.push_back(onAns);
                }
                return curAns;
            }

            if(nexts.size() == 0) { // if no word find ,return 
                return curAns;
            }

            // remove current find word from dict 
            for(it = nexts.begin();it != nexts.end();it ++) {
                dict.erase(*it);
            }
            // find nexts anser
            vector<vector <string> > nextAns = findAns(nexts,end,dict);
            for(int i = 0; i < nextAns.size(); i ++) {
                if(nextAns[i].size() <=0)continue;
                string first = nextAns[i][0];
                for(int j=0; j < cur_pre[first].size(); j++) {
                    vector<string> oneAns;
                    string pre = string(cur_pre[first][j]);
                    oneAns.push_back(pre);
                    for(int k = 0; k < nextAns[i].size(); k ++) {
                        oneAns.push_back(string(nextAns[i][k]));
                    }
                    curAns.push_back(oneAns);
                }
            }
            return curAns;

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
        vector<vector <string> > ans = so.findLadders(start,end,dict);
        for(int id = 0; id < ans.size(); id ++) {
            for(int j=0; j < ans[id].size(); j++) {
                cout << ans[id][j] << ",";
            }
            printf("\n");
        }
    }
}
