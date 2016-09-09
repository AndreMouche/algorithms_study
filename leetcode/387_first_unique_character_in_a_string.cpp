class Solution {
public:
    int firstUniqChar(string s) {
        int a[300];
        memset(a,0,sizeof(a));
        for(int id=0;id<s.length();id++) {
          a[s[id]]++;
        }
        for(int id=0;id<s.length();id++) {
           if(a[s[id]]==1) {
              return id;
           }
        }
        return -1;
    }
};
