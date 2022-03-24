#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
int isused[10];
// back tracking : 모든 경우를 다 들어다 가본다.
void func(int k){
    // base condition
    if (k == m){
        for (int i = 0; i < m;i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    // 자식 노드로 내려가는 순간 1~n 까지 무조건 탐색함. 따라서 중복 허용이다.
    for (int i = 1; i <= n; i++){
        if (!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; // 1 ~ n 수 중에서 m 수의 부분집합 구하기
    func(0);
}