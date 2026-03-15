#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int32_t main(){
    int n; cin >> n;
    int sum = 0; int a; cin >> a;
    for(int i = 1; i < n; i++){ int b; cin >> b; if(b < a) sum += a-b; a = max(a, b); }
    cout << sum << endl;
}
