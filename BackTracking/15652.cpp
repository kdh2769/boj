#include <bits/stdc++.h>
using namespace std;
int m, n;
int arr[10];

void func3(int k){
    if (k == m){
        for (int i = 0; i < m; i ++)
            cout << arr[i]  << ' ';
        cout << '\n';
        return ;
    }
    int st = 1;
    if(k != 0) st = arr[k-1];
    for (int i = st; i <= n; i++ ){
        arr[k] = i;
        func3(k+1);
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func3(0);
}
