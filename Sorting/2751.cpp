#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int tmp[1000001];
// divide 할때 2*N-1 번 divide 함수 호줄 한다 -> O(N)
// merge 는 k 번째 줄마다 N 번 시행한다 -> O(Nk) = log(N) -> Nlog(N)
// st, en 의 관계는 arr[st:en]이다. st<=i<en
void merge(int st, int en){
    int mid = (st+en)/ 2;
    int lidx = st;
    int ridx = mid;
    for (int i = st; i < en; i++){
        if(ridx == en) tmp[i] = arr[lidx++];
        else if (lidx == mid) tmp[i] = arr[ridx++];
        else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for (int i = st; i < en; i ++) arr[i] = tmp[i];
}

void mergeSort(int st, int en){
    if (en-st == 1) return;
    int mid = (st+en)/2;
    mergeSort(st, mid);
    mergeSort(mid, en);
    merge(st, en);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> arr[i];
    mergeSort(0, n);
    for (int i = 0; i < n; i ++) cout <<  arr[i] << '\n';
}
