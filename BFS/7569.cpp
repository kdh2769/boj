#include <bits/stdc++.h>
using namespace std;

int dx[6] = {0, 0, 1, 0, -1, 0};
int dy[6] = {0, 0, 0, 1, 0, -1};
int dz[6] = {1, -1, 0, 0, 0, 0 };
int board[104][104][104];
int dist[104][104][104];
int m, n, h;
queue<tuple<int ,int, int>> q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    // 3차원
    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j ++){
            for (int k = 0; k < m; k ++){
                int temp;
                cin >> temp;
                board [j][k][i] = temp;
                if (temp == 1) q.push({j, k, i});
                if (temp == 0) dist[j][k][i] = -1;
            }
        }
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        for (int dir = 0; dir < 6; dir ++){
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h ) continue;
            if (board[nx][ny][nz] == -1 || dist[nx][ny][nz] >= 0) continue;
            q.push({nx, ny, nz});
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j ++){
            for (int k = 0; k < m; k ++){
                int temp = dist[j][k][i];
                if ( temp == -1){
                    cout << -1;
                    return 0;
                }
                cnt = max(cnt, temp);
            }
        }
    }
    cout << cnt;
    return 0;
}