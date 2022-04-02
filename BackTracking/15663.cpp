#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[10];
int arr[10];
bool vis [10];
void func(int k){

    if (k == m){
        for (int i = 0 ;i < m ; i ++)
            cout << board[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++){
        if (board[i-1] == board [i] && !vis[i-1]) continue;
        if (vis[i]) continue;
        arr[k] = i;
        vis[i] = true;
        func(k+1);
        vis[i] = false;
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