#include<bits/stdc++.h>
using namespace std;

int main(){
    int l1 = 0, l2 = 0;
    int n, on; cin >> n;

    for(int i = 0; i < n; i++){
        cin >> on;
        if(on == 1) l1 = !l1;
        else{
            l1 = !l1;
            l2 = !l2;
        }
    }
    cout << l1 << endl << l2;
}