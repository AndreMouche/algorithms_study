#include<stdio.h>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
struct Point {
 int x;
 int y;
 Point() : x(0), y(0) {}
 Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
       if (points.size()<=2){
            return points.size();      
       }
       int max = 0;
       for(int i = 0; i < points.size(); i ++ ){
          Point it = points[i];
          map<float,int> nums;
          nums.clear();
          int base = 0;//落在当前节点上的点个数
          int xNum =0; //斜率为0的点
          for(int j=0; j < points.size(); j ++ ){
               Point p = points[j];
               if(p.x==it.x && p.y == it.y) {
                  base ++;
                  continue;
               }
              if (p.x == it.x) {
                  xNum ++;
                  continue;
              }

              float k = float(p.y-it.y)/(p.x-it.x*1.0);
              if(nums.find(k)== nums.end()){
                 nums[k] = 1;
              } else {
                 nums[k]++;
              }
          
          }
          
          xNum += base;
          if(xNum>max) {
             max = xNum;
          }

          map<float,int>::iterator mIt;
          for (mIt=nums.begin();mIt!=nums.end();mIt++) {
              int curNum = base+mIt->second;
              if (curNum > max){
                   max = curNum;             
              }
           
          }
          
       
       }
       return max;
    }
   
};

int main(){
   int n;
   Solution solution = Solution();
   while(scanf("%d",&n)!= EOF) {
      if (n==0) {
        break;       
      }
      int id;
      vector<Point> points;
      for(id = 0; id < n; id ++) {
         Point p = Point();
         scanf("%d %d",&p.x,&p.y);
         points.push_back(p);
      }
      cout << solution.maxPoints(points)<<endl;
   }
   return 0;
}

/*
testData:
1
1 1
2
1 1
1 2
5
1 1
2 2
3 3
3 4
5 5

output
1
2
4
*/


