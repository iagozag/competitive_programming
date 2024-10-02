#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, q; cin >> n >> q;
    vector<ll> v(n); for(auto& x: v) cin >> x;

    vector<ll> sum(n);
    for(int i = 0; i < n; i++){
        sum[i] += 1LL*i*1LL*(n-i)+1LL*(n-i-1);
    }
    map<ll, ll> mp; 
    for(int i = 0; i < n; i++) mp[sum[i]]++;
    for(int i = 0; i < n-1; i++){
        mp[sum[i]-i] += v[i+1]-v[i]-1LL;
    }

    for(int i = 0; i < q; i++){
        ll k; cin >> k;
        cout << mp[k] << " ";
    }
    cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
