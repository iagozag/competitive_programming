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

vl fact(MAX), ifact(MAX);

ll fexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = ans*a%MOD;
        a = a*a%MOD, b >>= 1;
    }
    return ans;
}

ll comb(int a, int b){
    return fact[a]*ifact[b]%MOD*ifact[a-b]%MOD;
}

void solve(){
    ll n, k; cin >> n >> k;
    vl v(n); forr(x, v) cin >> x;
    sort(all(v));
    ll ans = 0; ll need = k/2;
    rep(i, 0, n) if(v[i]){
        if(need > i or n-i-1 < need) continue;
        ans = (ans+(comb(i, need)*comb(n-i-1, need)%MOD))%MOD;
    }
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    rep(i, 2, MAX) fact[i] = fact[i-1]*i%MOD, ifact[i] = ifact[i-1]*fexp(i, MOD-2)%MOD;


    while(ttt--) solve();

    exit(0);
}
