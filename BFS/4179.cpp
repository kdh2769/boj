#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx [4] = {1, 0, -1, 0};
int dy [4] = {0, 1, 0, -1};
string board[1002];
int dir1[1002][1002];
int dir2[1002][1002];
int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<pair<int, int>> Qf;
    queue<pair<int, int>> Qj;
    for (int i = 0; i < n; i ++)
        cin >> board[i] ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'J') {
                Qj.push({i,j});
            } else if (board[i][j] == 'F') {
                Qf.push({i, j});
            }
        }
    }
    while(!Qf.empty()){
        pair<int, int> cur = Qf.front(); Qf.pop();
        for (int i = 0; i < 4 ; i ++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == '#' || dir1[nx][ny] > 0) continue;
            dir1[nx][ny] = dir1[cur.X][cur.Y] + 1;
            Qf.push({nx, ny});
        }
    }

    while(!Qj.empty()){
        pair<int, int> cur = Qj.front();
        Qj.pop();
        for (int i = 0; i < 4 ; i ++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                cout << dir2[cur.X][cur.Y] + 1 ;
                return 0;
            }
            if (board[nx][ny] == '#' || dir2[nx][ny] > 0) continue;
            if (dir1[nx][ny] != 0 && dir1[nx][ny] <= dir2[cur.X][cur.Y] + 1) continue;
            dir2[nx][ny] = dir2[cur.X][cur.Y] + 1;
            Qj.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}
