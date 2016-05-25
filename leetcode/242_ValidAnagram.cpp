bool isAnagram(char* s, char* t) {
    if(strlen(s)!=strlen(t)) {
        return false;
    }
    int ans[300];
    memset(ans,0,sizeof(ans));
    int id = 0;
    for(id=0;id<strlen(s);id++){
        ans[s[id]] ++;
        ans[t[id]] --;
    }
    
    for(id=0;id<300;id++){
        if(ans[id]!=0)return false;
    }
    return true;
}
