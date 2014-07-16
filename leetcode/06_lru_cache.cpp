#include<stdio.h>
#include<map>
#include<list>
using namespace std;

/**

*/

class LRUCache{
public:
    LRUCache(int Capacity) {
       capacity = Capacity;
    }
    
    //O(logN)
    int get(int key) {
       if(data.find(key)==data.end()) {
           return -1;
       }

       keyList.erase(add[key]);
       keyList.push_front(key);
       add[key] = keyList.begin();
       return data[key];
    }
    //O(logN)
    void set(int key, int value) {
       data[key] = value;
       if(add.find(key)!=add.end()){
           keyList.erase(add[key]);
       }
       keyList.push_front(key);
       add[key] = keyList.begin();
       if(data.size()>capacity){
          int rmKey = keyList.back();
          data.erase(rmKey);
          add.erase(rmKey);
          keyList.pop_back();
       }
       //printf("set %d %d,datasize %ld , %d\n",key,value,data.size(),capacity);
    }
private:
   int capacity;
   map<int,int> data;
   list<int> keyList;
   map<int,list<int>::iterator> add;

};

int main(){
 int n;
 char op[5];
 while(scanf("%d",&n)!=EOF){
  LRUCache cache = LRUCache(n);
  int t;
  scanf("%d",&t);
  while(t--){
  scanf("%s",op);
  if(op[0]=='s' ){
    int key,value;
    scanf("%d%d",&key,&value);
    cache.set(key,value);
  }else {
      int key;
      scanf("%d",&key);
      printf("%d\n",cache.get(key));
  
  }
  
  }
 
 }
 return 0;
}
