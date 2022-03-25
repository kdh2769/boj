#include <bits/stdc++.h>
using namespace std;
int n, s;
int cnt = 0;
int arr[20];

void func(int cur, int tot){
   if (cur == n){
       if (tot == s)
           cnt++;
       return;
   }

   func(cur+1, tot); // 해당 index 수는 0,1,,n 의 arr 에서 포함 안시킴
   func(cur+1, tot+arr[cur]);// 해당 index 수는 0,1,,n 의 arr 에서 포함 시킴
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0 ; i < n; i++)
        cin >> arr[i];
    func(0, 0);
    if(s == 0) cnt --;
    cout << cnt;
}