#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long a, b, m; cin >> a >> b >> m;
    
    if(a%m == b%m) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
