#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
       if(tokens.size() == 0 ){
           return 0;
       }
       vector<int> nums;
       vector<string>::iterator it;
       for(it=tokens.begin();it!=tokens.end();it++) {
          int curNum = 0;
          if(*it=="+" || *it== "-" || *it == "*" || *it == "/") {
            int right = nums.back();
            nums.pop_back();
            int left = nums.back();
            nums.pop_back();
            if (*it == "+") {
               curNum = left+right;
            } else if (*it == "-") {
               curNum = left-right;
            } else if (*it == "*"){
               curNum = left * right;
            } else {
               curNum = left/right;
            }

          } else {
               
             curNum = atoi((*it).c_str());
          }
          nums.push_back(curNum);
       }
       if (nums.size()>0) {
         return nums.back();
       }
         return 0;
    }
};

void trim(string &s,string c) {
  if (s.empty()) {
    return ;
  }
  s.erase(0,s.find_first_not_of(c));
  s.erase(s.find_last_not_of(c)+1);
}

int main(){
    Solution solution = Solution();
    string input;
    while(true){
       getline(cin,input);
       vector<string> tokens;
       while(true){
         int left=input.find_first_of('"');
         if (left == -1 ) {
            break;
         }
         input = input.substr(left+1,input.length());
         int right = input.find_first_of('"');
         if (right==-1) {
           break;
         }
         string value = input.substr(0,right);
//         cout << value<< endl;
         tokens.push_back(value);
         input = input.substr(right+1,input.length());
       }

       vector<string>::iterator it;
       for (it=tokens.begin();it != tokens.end(); it++){
                cout << *it << " ";     
       }
       cout << endl ;
       cout << solution.evalRPN(tokens)<< endl;
    }
    

}

