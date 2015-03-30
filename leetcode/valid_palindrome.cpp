/**
 *https://leetcode.com/problems/valid-palindrome/
 */
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int left,right;
            left = 0;
            right = s.size()-1;
            while(left <=right) {
                char cl,cr;
                cl = lower(s[left]);
                if(!isLegal(cl)) {
                    left += 1;
                    continue;
                }

                cr = lower(s[right]);
                if(!isLegal(cr)) {
                    right -= 1;
                    continue;
                }

                if(cl != cr) {
                    return false;
                }

                right -=1;
                left +=1;

            }
            return true;
        }

        bool isLegal(char c) {
            if(c>='0' && c<='9') {
                return true;
            }
            if(c < 'a' || c > 'z') {
                return false;
            }
            return true;
        }

        char lower(char c) {
            if(c >='A' && c<= 'Z') {
                c = c - 'A' + 'a';
            }
            return c;
        }
};

int main() {
    Solution so;
    char a[1000];
    while(gets(a)) {
        cout << so.isPalindrome(a) << endl;
    }
    return 0;
}
