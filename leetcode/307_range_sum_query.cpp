#include<stdio.h>
#include<vector>
using namespace std;
struct Node {
  int left;
  int right;
  int sum;
  Node* nleft;
  Node* nright;
  Node(){}
  Node(int l,int r) {
    left=l;
    right=r;
    nleft=NULL;
    nright=NULL;
  }
};

class NumArray {
public:
    Node* root;
    vector<int> nums;
    // sum[i][length]=sum{num[i],num[i+1],..num[i+length-1]}=sum[i][length-1]+num[i+leng-1]
    NumArray(vector<int> &nums) {
       this->nums=nums;
       this->root=CreateTree(0,nums.size()-1);
    }

    Node* CreateTree(int l,int r) {
      if(l>r)return NULL;
      Node* cur= new Node(l,r);
      if(l==r) {
        cur->sum=nums[l];
        return cur;
      }
      int mid=(l+r)>>1;
      cur->nleft=CreateTree(l,mid);

      cur->nright=CreateTree(mid+1,r);

      cur->sum=0;
      if(cur->nleft!=NULL) {
        cur->sum+=cur->nleft->sum;
      }
      if(cur->nright!=NULL) {
        cur->sum+=cur->nright->sum;
      }
      return cur;
    }

    int computeSum(Node* node,int left,int right) {
         if(node==NULL) {
           return 0;
         }
         if(left<=node->left&&right>=node->right) {
           return node->sum;
         }
         int mid=(node->left+node->right)>>1;
         int ans = 0;

         if(left<=mid) {
           ans+=computeSum(node->nleft,left,right);

         }
         if(right>mid) {
           ans+=computeSum(node->nright,left,right);
         }
         return ans;
    }

    void updateNode(Node *node,int i,int val) {
      if(node->left==node->right) {
         if(node->left==i) {
           node->sum=val;
         }
        return;
      }
      int mid=(node->left+node->right)>>1;
      if(i<=mid) {
        updateNode(node->nleft,i,val);
      } else {
        updateNode(node->nright,i,val);
      }
      node->sum=node->nleft->sum+node->nright->sum;
    }

    void update(int i, int val) {
         updateNode(root,i,val);
    }

    int sumRange(int i, int j) {
         return computeSum(root,i,j);
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
