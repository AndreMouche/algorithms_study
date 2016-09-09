class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length()>magazine.length()) {
            return false;
        }
        int a[300];
        memset(a,0,sizeof(a));
        for(int id=0;id<magazine.length();id++) {
           a[magazine[id]]++;
        }
        for(int id=0;id<ransomNote.length();id++) {
          a[ransomNote[id]]--;
          if(a[ransomNote[id]]<0) {
            return false;
          }
        }
        return true;
    }
};
