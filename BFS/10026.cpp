#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[101];
bool vis [101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

queue<pair<int , int>> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0 ; i < n; i ++){
        cin >> board[i];
    }

    int cnt = 0;
    for (int x = 0; x < n ; x++) {
        for (int y = 0; y < n; y++){
            if (vis[x][y]) continue;
            q.push({x, y});
            cnt ++;
            while (!q.empty()){
                pair <int, int >cur = q.front(); q.pop();
                vis[x][y] = 1;
                for (int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (board[nx][ny] != board[cur.X][cur.Y] || vis[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    cout << cnt << '\n';
    cnt = 0;
    memset(vis, 0, sizeof (vis));
    for (int x = 0; x < n ; x++) {
        for (int y = 0; y < n; y++){
            if (vis[x][y]) continue;
            q.push({x, y});
            cnt ++;
            while (!q.empty()){
                pair <int, int >cur = q.front(); q.pop();
                vis[x][y] = 1;
                for (int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if ((board[nx][ny] == 'R' && board[cur.X][cur.Y] == 'G') || (board[nx][ny] == 'G' && board[cur.X][cur.Y] == 'R')){
                        if (vis[nx][ny]) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                    if (board[nx][ny] != board[cur.X][cur.Y] || vis[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    cout << cnt;
}
