#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vl dpv(vl v, int m){
    int n = sz(v);
    vl dp(1<<n);
    rep(i, 0, 1<<n){
        rep(j, 0, n) if((1<<j)&i){
            ckmax(dp[i], (dp[i^(1<<j)]+v[j])%m);
        }
    }

    return dp;
}

void solve(){
    ll n, m; cin >> n >> m;
    vl v1, v2;
    rep(i, 0, n){
        int a; cin >> a; a %= m;
        if(i < n/2) v1.eb(a);
        else v2.eb(a);
    }

    int ma = 0;
    vl dp1 = dpv(v1, m), dp2 = dpv(v2, m);
    set<int> s1(all(dp1)), s2(all(dp2));
    sort(all(dp2));
    forr(x, dp1){
        int need = m-1-x;
        int idx = lower_bound(all(dp2), need)-dp2.begin();
        if(idx < 0 or idx > sz(dp2)) continue;

        if(idx < sz(dp2) and dp2[idx] == need) ckmax(ma, (x+dp2[idx])%m);
        else if(idx > 0) ckmax(ma, (x+dp2[idx-1])%m);
    }

    cout << ma << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
