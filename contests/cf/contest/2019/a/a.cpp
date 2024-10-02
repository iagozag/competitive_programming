#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> v(n); for(auto& x: v) cin >> x;
    int ans = 0, ma = 0, sum = 0;
    for(int i = 0; i < n; i += 2) ma = max(ma, v[i]), sum++;
    ans = ma+sum;
    ma = 0, sum = 0;
    for(int i = 1; i < n; i += 2) ma = max(ma, v[i]), sum++;
    cout << max(ans, ma+sum) << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
