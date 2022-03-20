#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board [102];
int dir [102][102];
int dx[4] = {1, 0 ,-1, 0};
int dy[4] = {0, 1 ,0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // 붙어서 입력되는 값 처리 matrix 로 처리 가능함.
    for (int i = 0; i < n; i ++){
        cin >> board[i];
    }
    queue<pair<int, int>>Q;
    Q.push({0, 0});
    while (!Q.empty()){
        pair<int ,int> cur;
        cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++){
           int nx = cur.X + dx[i];
           int ny = cur.Y + dy[i];
           if (nx<0 || nx >= n || ny < 0 || ny >= m) continue;
           if (dir[nx][ny] != 0 || board[nx][ny] == '0') continue; // string 고려해서 문자열로 확인
           dir[nx][ny] = dir[cur.X][cur.Y] + 1;
           Q.push({nx, ny});
        }
    }
    cout << dir[n-1][m-1] + 1;
}
