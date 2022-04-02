#include <bits/stdc++.h>
using namespace std;

int m;
int board[50];
int arr[50];

void func(int k){
    if (k == 6){
        for (int i = 0 ;i < 6 ; i ++)
            cout << board[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    int st = 0;
    if (k != 0) st = arr[k-1] + 1;
    for (int i = st; i < m; i++){
        arr[k] = i;
        func(k+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> m;
        if(m == 0)
            return 0;

        for (int i = 0; i < m; i ++){
            cin >> board[i];
        }
        func(0);

        fill (board, board + m, 0);
        fill (arr, arr + m, 0);
        cout << '\n';
    }
}