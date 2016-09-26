#include<stdio.h>
#include<vector>
using namespace std;
class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int> &nums) {
       if(nums.size()<=0) {
         return;
       }
       sums.push_back(nums[0]);
       for(int id=1;id<nums.size();id++) {
           sums.push_back(sums[id-1]+nums[id]);
       }
    }
    int sumRange(int i, int j) {
         if(i==0)return sums[j];
         return sums[j]-sums[i-1];
    }
};


int main(){
  int data[] = {-2, 0, 3, -5, 2, -1};
  vector<int> nums;
  for(int id=0;id<6;id++) {
    nums.push_back(data[id]);
  }
  NumArray s(nums);
  printf("%d\n",s.sumRange(0,1) );
  printf("%d\n",s.sumRange(1,2) );
    printf("%d\n",s.sumRange(0,2) );
}
