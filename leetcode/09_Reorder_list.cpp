#include<stdio.h>
#include<vector>
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
      void reorderList(ListNode *head){
          if(head==NULL) {
             return;
          }
          vector<ListNode*> listNode;
          for(ListNode *curNode = head;curNode != NULL; curNode=curNode->next){
              listNode.push_back(curNode);   
          }  
         
          for(ListNode *curNode = head;;){
             ListNode *tail = listNode.back();
             listNode.pop_back();
             ListNode *curNext = curNode->next;
             if(tail == curNext||tail == curNode){
                tail->next = NULL;
                break;
             }
             curNode->next = tail;
             tail->next = curNext;
             curNode = curNext;
          }
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
    cout << "TO order" << endl;
    ListNode *head = &nodes[0];
    solution.reorderList(head);
    cout << "finished" << endl;
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
