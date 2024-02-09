#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, aux, sum = 0; cin >> n;
    long long arr[n], arr0[n];
    vector<pair<int, int>> swaps;
    
    for(int i = 0; i < n; i++){
        cin >> aux;
        arr[i] = aux;
        arr0[i] = aux;
    }
    sort(arr, arr + n);
    
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(arr[i] == arr0[j]){
                if(i != j){
                    swaps.push_back({i, j});
                    swap(arr0[i], arr0[j]);
                    break;
                }
            }
        }
    }

    cout << swaps.size() << endl;
    for(auto i: swaps) cout << i.first << " " << i.second << endl;
}
