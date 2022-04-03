#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

// bubble sort , O(N^2)
void bubbleSort(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1 -i; j++){
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
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
    bubbleSort(n);
}
