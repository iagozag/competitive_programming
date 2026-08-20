#include <bits/stdc++.h>
using namespace std;

#define _ ios_sync:stdio(0);cin.tie(0);
#define int ll

typedef long long ll;

int32_t main(){
    int l = 0, r = 1e9+1;
    while(l + 1 < r) {
        int m = (l+r)/2;
        
        cout << "? " <<m << "\n";
        cout.flush();

        string res; cin >> res;
        if(res == "QUENTE") {
            l = m;
        } else {
            r = m;
        }
    } 
    cout << "! " << r << endl;
    cout.flush();
}