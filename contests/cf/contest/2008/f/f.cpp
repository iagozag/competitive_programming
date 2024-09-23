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

const int MAX = 2e5+10, MOD = 1e9+7;

ll fexp(ll a, ll b){
    a %= MOD;
    ll ans = 1;
    while(b){
        if(b&1) ans = ans*a%MOD;
        a = a*a%MOD, b >>= 1;
    }
    return ans;
}

void solve(){
    ll n; cin >> n;
    vl v(n); forr(x, v) cin >> x;
    vl pref(n); pref[n-1] = v[n-1];
    per(i, n-2, 0) pref[i] = pref[i+1]+v[i], pref[i] %= MOD;
    ll sum = 0;
    rep(i, 0, n-1) sum += v[i]*pref[i+1], sum %= MOD;
    cout << sum*fexp(n*(n-1)/2LL, MOD-2)%MOD << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
