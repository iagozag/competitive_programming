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

void solve(){
    ll n, x; cin >> n >> x;
    vl v1, v2;
    rep(i, 0, n){
        ll a; cin >> a;
        if(i&1) v1.eb(a);
        else v2.eb(a);
    }

    int n1 = sz(v1), n2 = sz(v2);
    vl dp1(1<<n1), dp2(1<<n2);
    rep(i, 0, 1<<n1) rep(j, 0, n1) if((1<<j)&i) dp1[i] = dp1[i^(1<<j)]+v1[j];
    rep(i, 0, 1<<n2) rep(j, 0, n2) if((1<<j)&i) dp2[i] = dp2[i^(1<<j)]+v2[j];

    ll ans = 0; 
    sort(all(dp2));
    rep(i, 0, 1<<n1){
        ll need = x-dp1[i];
        int idx = lower_bound(all(dp2), need)-dp2.begin();
        int idxu = upper_bound(all(dp2), need)-dp2.begin();
        if(idx < (1<<n2) and dp2[idx] == need) ans += idxu-idx;
    }
    
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
