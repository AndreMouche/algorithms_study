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
    ListNode *insertionSortList(ListNode *head) {
       if(head==NULL || head->next == NULL) {
          return head;
       }

       ListNode *curTail = head;
       for(ListNode *curNode = head->next;curNode!=NULL;curNode=curTail->next) {
              ListNode *p;
              if(head->val >= curNode->val) {
                  curTail->next = curNode->next;
                  curNode->next = head;
                  head = curNode;
                  continue;
              }

              bool flag = false;
              for(p = head;p->next!=curNode; p = p->next) {
                    if(p->next->val>curNode->val) {
                        curTail->next = curNode->next;
                        curNode->next = p->next;
                        p->next = curNode;
                        flag = true;
                        break;
                    }
              }

              if(flag==false) {
                  curTail = curTail->next;
              }
       }

       return head;
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
    cout << "fdas" << endl;
    ListNode *head = solution.insertionSortList(&nodes[0]);
    cout << "finished sort" << endl;
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
