#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
// selection sort
// O(N^2)
void selectionSort1(int n){
    for (int i = n-1 ; i > 0 ; i--){
        int mxidx = 0;
        for (int j = 1; j <= i; j++){
            if (arr[mxidx] < arr[j])
                swap(arr[mxidx], arr[j]);
        }
        swap(arr[mxidx], arr[i]);
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << '\n';
    }
}
void selectionSort2(int n){
    for (int i = n-1 ; i > 0; i--){ // i = arr 의 index , size - 1
        swap (*max_element(arr, arr + i + 1), arr[i]);
        // max_element 는 size 가 필요함 ,i + 1
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> arr[i];  //
    }
    //selectionSort1(n);
    //selectionSort2(n);

}
