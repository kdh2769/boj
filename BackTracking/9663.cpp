#include <bits/stdc++.h>
using namespace std;
int n, cnt;
// 놓을때 마다 col, X 자 대각선을 확인하는 O(n) 아닌 bool로 (1) 로 처리하는 방식
bool isused1[40]; // col 값 점검
bool isused2[40]; // 기울기 1 양수 대각선 확인
bool isused3[40]; // 기울기 -1 음수 대각선 확인

void func(int k){
    if (k == n ){
        cnt ++;
        return;
    }
    for (int i = 0; i < n; i++){
        if(isused1[i] || isused2[i + k] || isused3[k - i + n - 1])
            continue;
        isused1[i] = 1;
        isused2[i + k] = 1;
        isused3[k - i + n - 1] = 1; //
        func(k + 1);
        isused1[i] = 0;
        isused2[i + k] = 0;
        isused3[k - i + n - 1] = 0; //
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}