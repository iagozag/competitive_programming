#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
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

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 998244353;

void solve(){
    int n; ll k; cin >> n >> k;
    vl v(n); forr(x, v) cin >> x;

    vl pref(n+1); map<ll, ll> mp;
    rep(i, 1, n+1) pref[i] = pref[i-1]+v[i-1];

    vl dp(n+1), dppref(n+1); dp[0] = 1, dppref[0] = 1, mp[0] = 1;
    rep(i, 1, n+1){
        dp[i] = dppref[i] = dppref[i-1];
        dp[i] -= mp[pref[i]-k], dp[i] += MOD, dp[i] %= MOD;
        mp[pref[i]] += dp[i], mp[pref[i]] %= MOD, dppref[i] += dp[i], dppref[i] %= MOD;
    }

    cout << dp[n] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
