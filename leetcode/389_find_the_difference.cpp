class Solution {
public:
    char findTheDifference(string s, string t) {
        int a[300];
        memset(a,0,sizeof(a));
        for(int id=0;id<s.length();id++) {
           a[s[id]]++;
        }
        for(int id=0;id<t.length();id++) {
          a[t[id]]--;
          if(a[t[id]]<0) {
            return t[id];
          }
        }
        return ' ';
    }
};
