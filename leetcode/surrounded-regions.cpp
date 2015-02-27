/**
 https://oj.leetcode.com/problems/surrounded-regions/
 breadth first search
*/
#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

class Solution {
    public:
        void solve(vector< vector<char> > &board) {
            if(board.size()==0) {
                return;
            }
            int i,j;
            char op = 'O';
            for(i = 0; i < board.size();i ++) {
                if(board[i][0] == 'O') {
                    bfs(i,0,board);
                }
                if(board[i][board[i].size()-1] == 'O') {
                    bfs(i,board[i].size()-1,board);
                }
            }

            for(i = 0; i < board[0].size(); i ++) {
                if(board[0][i] == 'O') {
                    bfs(0,i,board);
                }
            }

            for(i = 0; i < board[board.size()-1].size();i ++) {
                if(board[board.size()-1][i] == 'O') {
                    bfs(board.size()-1,i,board);
                }
            }

            for(i = 0; i < board.size(); i ++) {
                for(j=0;j < board[i].size();j++) {
                    if(board[i][j] == 'O') {
                        board[i][j] = 'X';
                    } else if(board[i][j] =='v') {
                        board[i][j] = 'O';
                    }
                }
            }
        }

        void bfs(int i,int j, vector< vector<char> > &board) {
            queue<int> skeys;
            int heigh = board.size();
            skeys.push(heigh*j+i);
            board[i][j] = 'v';
            int dxy[4][2] = {{0,1},
                {0,-1},{-1,0},{1,0}};

            while(!skeys.empty()) {
                int cur = skeys.front();
                skeys.pop();
                int ii,jj;
                ii = cur%heigh;
                jj = cur/heigh;
                for(int k = 0; k < 4; k++) {
                    int curi = ii + dxy[k][0];
                    int curj = jj + dxy[k][1];
                    if(curi < 0 || curi >= heigh) {
                        continue;
                    } 

                    if(curj < 0 || curj >= board[curi].size()) {
                        continue;
                    }

                    if(board[curi][curj] == 'O') {
                        board[curi][curj] = 'v';
                        skeys.push(curj*heigh + curi);
                    }
                }
            }
        }

};

int main() {
    int n;
    string s;
    Solution solution;
    while(scanf("%d",&n)!=EOF) {
        vector< vector<char> > board;
        for(int t = 0; t < n; t ++) {
            cin>>s;
            //      cout << s << endl;
            vector<char>cur;
            for(int id = 0; id < s.size(); id ++) {
                cur.push_back(s.at(id));
                //           cout << s.at(id);
            }
            //        cout << endl;
            board.push_back(cur);
        }

        solution.solve(board);

        printf("n=%d\n",n);
        for(int id=0; id < board.size(); id ++) {
            for(int j = 0; j < board[id].size(); j ++) {
                printf("%c",board[id][j]);  
            }
            printf("\n");
        }
        printf("\n");
    }

}
