#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[10];
int arr[10];
bool vis[10];

void func(int k){
    if (k == m){
        for (int i = 0 ;i < m ; i ++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int st = 0;
    if (k != 0) {
        for (int i = 0; i < n; i++) {
            if (arr[k - 1] == board[i])
                st = i;
        }
    }
    for (int i = st; i < n; i++){
        if (vis[i]) continue;
        arr[k] = board[i];
        vis[i] =1;
        func(k+1);
        vis[i] = 0;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m ;
    for (int i = 0; i < n ; i ++){
       cin >> board[i];
    }
    sort (board, board + n);
    func(0);
    return 0;
}