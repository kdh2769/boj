#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
int dirt[502][502];
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int main(void){
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++){
            scanf("%1d", &board[i][j]);
            dirt[i][j] = 0;
        }
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dirt[0][0] = 1;
    while (!Q.empty()){
        pair<int, int> cur= Q.front(); Q.pop();
        for (int i = 0; i < 4; i ++){
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if (nx >= n || ny >= m || nx < 0|| ny < 0 ) continue;
            if (board[nx][ny] != 1 || dirt[nx][ny]) continue;
                dirt[nx][ny] = dirt[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
        }
    }
    cout << dirt[n - 1][m - 1];
}