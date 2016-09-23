#include<stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
      int n = A.size();
      int sum = 0;
      int ans = 0;
      for(int id=0;id<n;id++) {
         ans=ans+A[id]*id;
         sum+=A[id];
      }

      int pre=ans;
      for(int id=n-1;id>0;id--) {
          pre=pre+sum-A[id]*n; //当前旋转的值，F(n-id)的值
          ans=pre>ans?pre:ans;
      }
      return ans;
    }
};

int main() {
  Solution s;
  int data[]={4,3,2,6};
  vector<int> a;
  for(int id=0;id<4;id++) {
    a.push_back(data[id]);
  }
  printf("%d",s.maxRotateFunction(a));
}
