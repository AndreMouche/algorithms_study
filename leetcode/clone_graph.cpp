/**
 * https://oj.leetcode.com/problems/clone-graph/
 * deeply copy a struct of UndirectedGraphNode
 * recursion with help of map 
 */
#include<iostream>
#include<vector>
#include<map>
using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;

        map<int,UndirectedGraphNode*> nodes;
        return cloneNode(node,nodes);
    }

    UndirectedGraphNode *cloneNode(UndirectedGraphNode *node,map<int,UndirectedGraphNode*> &nodes) {
        if(node == NULL) {
            return NULL;
        }
        int id;
        UndirectedGraphNode *copyNode = new UndirectedGraphNode(node->label);
        nodes[copyNode->label] = copyNode;
        for(id = 0; id < node->neighbors.size(); id ++) {
              map<int,UndirectedGraphNode*>::iterator it;
              UndirectedGraphNode *curNode;
              it = nodes.find(node->neighbors[id]->label);
              if (it == nodes.end()) {
                   curNode = cloneNode(node->neighbors[id],nodes);
              } else {
                   curNode = it->second;
              }
              copyNode->neighbors.push_back(curNode);
        }
        return copyNode;
    }
};

int main() {
   return 0;
}
