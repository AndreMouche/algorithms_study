int titleToNumber(char* s) {
    int ans = 0;
    int id;
    for(id=0;id<strlen(s);id++){
        ans=ans*26+s[id]-'A'+1;
    }
    return ans;
}
