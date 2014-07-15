#include<stdio.h>
#include<iostream>
using namespace std;

struct ListNode {
  int val; 
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(){}
};
class Solution {
public:
      ListNode *sortList(ListNode *head) {
         if(head == NULL) {
            return NULL;
         }
         ListNode *tail = head;
         while(tail->next!=NULL) {
           tail = tail->next;
         }
         
         ListNode *result = quickSort(&head,&tail);
         tail->next = NULL;
         return result;
      }

      ListNode *quickSort(ListNode **start,ListNode **end) {
         if(*start==*end) {
            return *start;
         }

         ListNode *mid = *start;
         ListNode *left=NULL,*leftTail,*right=NULL,*rightTail,*midTail;
         midTail = mid;
         for(ListNode *curNode=(*start)->next;;) {
              if(curNode->val == mid->val) {
                 midTail->next = curNode;
                 midTail = curNode;
              } else if(curNode->val < mid->val) {
                 if(left==NULL) {
                   left = curNode;
                   leftTail = curNode;
                 } else {
                   leftTail->next = curNode;
                   leftTail= curNode;
                 }
              } else {
                 if(right==NULL) {
                   right = curNode;
                   rightTail = curNode;
                 } else {
                   rightTail->next = curNode;
                   rightTail = curNode;
                 }
              }
              if (curNode==*end) {
                 break;
              } else {
                  curNode = curNode->next;
              }
         }
         if (left != NULL) {
            quickSort(&left,&leftTail);
         } 

         if (right != NULL) {
            quickSort(&right,&rightTail);
         }
         if(left != NULL) {
            *start = left;
            leftTail->next = mid;
         } else {
             *start = mid;
         }

         midTail->next = right;
         if(right == NULL) {
            *end = midTail;
         } else {
            *end = rightTail;
         }
         return *start;
      }    

 };

int main(){
  Solution solution = Solution();
  int n;
  ListNode nodes[100];
  while(scanf("%d",&n)!=EOF) {
     if (n== 0) {
        break;
     }

     int x;
     for(int id=0; id < n; id ++) {
        scanf("%d",&x);
        nodes[id] = ListNode(x);
     }

     for (int id=1; id < n; id ++){
        nodes[id-1].next = &nodes[id];
     }
    ListNode *head = solution.sortList(&nodes[0]);
    ListNode *it;
     for(it=head;it!= NULL;it=it->next) {
        cout << it->val << " ";
        if(it==it->next) {
           cout << "Illegal" << endl;
           break;
        }
     }

     cout << endl;

  }
 
 }
