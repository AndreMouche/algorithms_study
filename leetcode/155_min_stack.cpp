#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
class MinStack {
public:
    map<int,int> data;
    vector<int> num;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
       map<int,int>::iterator it = data.find(x);
       if(it==data.end()) {
         data[x]=1;
       } else {
         data[x]=it->second+1;
       }
       num.push_back(x);
    }

    void pop() {
      if(num.empty()) {
         return;
      }
      int last=num.back();
      num.pop_back();
      data[last]--;
      if(data[last]<=0) {
        data.erase(last);
      }
    }

    int top() {
       if(num.empty()) {
         return 0;
       }
       return num.back();
    }

    int getMin() {
      if(data.empty()) {
        return 0;
      }
      return data.begin()->first;
    }
};

int main(){
   MinStack obj;
   obj.push(10);
   obj.push(20);
   obj.push(15);
   obj.pop();
   printf("%d\n", obj.top());
   printf("%d\n",  obj.getMin());
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
