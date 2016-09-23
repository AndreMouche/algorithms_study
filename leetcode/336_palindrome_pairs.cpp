#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

/**
1.单词a与单词b的反转匹配
2.需要切分情况,将当前单词切为left,right
a.right为回文，left的逆转存在
b.left为回文，right的逆转存在
枚举逆转串的长度即可。

注意：1不能合在2里面算，答案会重

*/
class Solution {
public:
    vector< vector<int> > palindromePairs(vector<string>& words) {
        vector< vector<int> > ans;
        unordered_map<string,int> wordsMap;
        set<int> lenSet;
        for(int id=0;id<words.size();id++) {
          wordsMap[words[id]]=id;
          lenSet.insert(words[id].size());
        }

        for(int id=0;id<words.size();id++) {
             string cur = words[id];
             reverse(cur.begin(),cur.end());

             // 存在与当前字符串反串一样的串
             if(wordsMap.count(cur)&&wordsMap[cur]!=id) {

               ans.push_back(newPair(id,wordsMap[cur]));
             }

             int curLen = cur.size();
             for(set<int>::iterator it=lenSet.begin();(*it)<curLen;it++) {
                 int wishLen = *it;
                 // 枚举匹配串的长度
                 // left(0,wishLen),right(wishLen+1,curLen)
                 // right是回文
                 if(isPalindrome(cur,wishLen,curLen-1) && wordsMap.count(cur.substr(0,wishLen))) {
                   ans.push_back(newPair(wordsMap[cur.substr(0,wishLen)],id));
                 }

                 //left是回文
                 if(isPalindrome(cur,0,curLen-wishLen-1)&&wordsMap.count(cur.substr(curLen-wishLen))) {
                   ans.push_back(newPair(id,wordsMap[cur.substr(curLen-wishLen)]));
                 }
             }
        }

        return ans;
    }

    vector<int> newPair(int a,int b) {
      vector<int> p;
      p.push_back(a);
      p.push_back(b);
    //  printf("pair %d,%d\n",a,b);
      return p;
    }

    bool isPalindrome(string a,int left,int right){
       while(left<=right&&a[left]==a[right]) {
         left++;
         right--;
       }
       return left>right;
    }


};


int main(){
  Solution s;
  string data[] = {"abcd","dcba","lls","s","sssll"};
  vector<string> words;
  for(int id=0;id<5;id++) {
    words.push_back(data[id]);
  }
  s.palindromePairs(words);
}
