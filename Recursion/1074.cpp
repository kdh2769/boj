#include <iostream>
using namespace std;

int r, c, N;
// 재귀는 basecondition (탈출조건), 함수의 정의 (뼈대), 재귀 식 (넘어가는 상황) 만 있으면 된다.
int func(int n,int r ,int c){
    if (n == 0)
        return 0; // 도미노의 시작점 (0, 0)을 찍고 출발한다.
    int half = 1 << (n-1);
    if (r < half && c < half) return func(n-1, r , c); // 2사분면
    if (r < half && c >= half ) return half*half + func(n-1, r, c-half); // 1사분면
    if (r >= half && c < half ) return 2*half*half + func(n-1, r-half, c); // 3사분면
    return 3*half*half + func(n-1, r-half, c-half); // 4 사분면
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> r >> c;
    cout << func(N, r , c);
}