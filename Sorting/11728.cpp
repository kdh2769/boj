#include <bits/stdc++.h>
using namespace std;

int n, m;
int iA ,iB;
int arrA[1000001];
int arrB[1000001];
int arrC[2000001];

void merge(){
    for (int i = 0; i < n+m ; i++){
        if (iA == n) arrC[i] = arrB[iB++];
        else if (iB == m) arrC[i] = arrA[iA++];
        else if (arrA[iA] < arrB[iB]) arrC[i] = arrA[iA++];
        else arrC[i] = arrB[iB++];
    }
    for (int i = 0; i < n + m; i++)
        cout << arrC[i] <<' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> arrA[i];
    for (int i = 0; i < m; i ++) cin >> arrB[i];
    merge();
}
