#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[8] = {2,1,-1, -2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int board[305][305];
int dir[305][305];
int l, nightX, nightY, goalX, goalY;
queue<pair<int,int>> q;

//  loop cases 수행시 q 초기화 안시킨다면 그냥 체스판 다 움직이고 출력하는 방법도 있음
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int loop = 0;
    cin >> loop;
    while (loop--) {
        cin >> l;
        cin >> nightX >> nightY;
        cin >> goalX >> goalY;
        q.push({nightX, nightY});
        dir[nightX][nightY] = 1;
        board[goalX][goalY] = 1;
        while (!q.empty()){
            pair<int, int >cur = q.front(); q.pop();
            for (int i = 0; i < 8; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (board[nx][ny]){
                    dir[nx][ny] = dir[cur.X][cur.Y] + 1;
                    break;
                }
                if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
                if (dir[nx][ny] != 0 ) continue;
                q.push({nx, ny});
                dir[nx][ny] = dir[cur.X][cur.Y] + 1;
            }
            if(dir[goalX][goalY]) break;
        }
        q = queue<pair<int,int>>(); // 여기 
        cout << dir[goalX][goalY] -1<< '\n';
        for(int i = 0; i < l; i ++){
            fill(dir[i], dir[i]+l, 0);
            board[goalX][goalY] = 0;
        }
    }
    return 0;
}