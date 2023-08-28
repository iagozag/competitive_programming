#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
    int n, min, min_ind; cin >> n;
    int num[n];
    vector<int> list(n);

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    for(int i = 0; i < n; i++){
        min = INF;
        for(int j = 0; j < n; j++){
            if(list[j] == 0 && num[j] < min){
                min = num[j];
                min_ind = j;
            }
        }
        cout << min <<  " ";
        list[min_ind] = 1;
    }
}