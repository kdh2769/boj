#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int day[1002][1002];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// 왜 queue를 사용해야할까. queue에는 익을 토마토가 순차적으로 들어간다. 
// 즉 00 111 222 33 이렇게 들어가기 때문에 아까 고민했던 max 를 사용해야할 이유가 없다. 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m ; j++){
            cin >> board[i][j];
            if (board[i][j] == 1) // 입력에서 시작점을 바로 큐에 집어 넣어준다.
                Q.push({i, j});
            if (board[i][j] == 0)
                day[i][j] = -1; // 토마토가 생성되었으면 -1 로 초기화시켜줘서 시간이 지난 후 -1 이라면 이 토마토는 익지 못한 것이다.
        }
    }
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i ++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0; nx >= n || ny >= m) continue; // board 밖엔 접근 하지 못하게 한다.
            if (day[nx][ny] >= 0) continue; // -1 로 결계가 생긴 곳은 day 값이 0 이다. 그거와 동시에 방문한 곳을 싸잡아서 못가게 한다.
                                            // board 검색을 안해도 되는 이유 : 값 입력 받을때 day 값도 죠져줘서
            day[nx][ny] = day[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j++){
            int cur = day[i][j];
            if (cur == -1){
                cout << -1;
                return 0;
            }
            ans = max(ans, cur);
        }
    }
    cout << ans;
}