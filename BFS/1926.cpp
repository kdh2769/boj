#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board [502][502];
bool vis [502][502];
int dx[4] = {1, 0 ,-1, 0};
int dy[4] = {0, 1 ,0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n , m; // n : row , m : col
    cin >> n >> m;
    // 그림 값 초기화
    for (int i = 0 ; i < n ; i++){
        for(int j = 0; j < m ; j++){
            cin >> board[i][j];
        }
    }
    int cnt = 0;
    int wide = 0;

    pair<int , int> p;
    queue<pair<int , int>>Q;
    // 그림 시작점 찾기
    for (int i = 0 ; i < n ; i++){
        for(int j = 0; j < m ; j++){
            if (board[i][j] == 0 || vis[i][j]) continue;
            Q.push({i, j});
            cnt ++;
            vis[i][j] = 1;
            int temp = 0;
            while (!Q.empty()){
                pair <int, int> cur = Q.front();
                temp++;
                Q.pop();
                for (int dir = 0 ; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            wide = max(temp, wide);
        }
    }
    cout << cnt << '\n' << wide;
}