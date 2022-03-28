#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int loop, n, m, b;
int board[52][52];
bool vis[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> loop;
    while (loop--) {
        cin >> m >> n >> b;
        int x, y;
        while(b--){
            cin >> x >> y;
            board[y][x] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && !vis[i][j]) {
                    vis[i][j] = true;
                    queue<pair<int, int>> Q;
                    Q.push({i, j });
                    while (!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (vis[nx][ny] || board[nx][ny] != 1) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny });
                        }
                    }
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        for(int i = 0; i < n; i++){
            fill(board[i], board[i]+m, 0);
            fill(vis[i], vis[i]+m, 0);
        }
    }
    return 0;
}
