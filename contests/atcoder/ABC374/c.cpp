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
    vector<ll> v(n); for(auto& x: v) cin >> x;

    vector<ll> sums(1<<n);
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < n; j++) if(i&(1<<j)) sums[i] = sums[i^(1<<j)]+v[j];
    }

    ll ans = LINF;
    for(int i = 0; i < (1<<n); i++) ans = min(ans, max(sums[i], sums[((1<<n)-1)^i]));
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
