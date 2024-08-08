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

bool eq(ll a, ll b, ll c, ll n){
    return a*b + a*c + b*c <= n;
}

bool eq2(ll a, ll b, ll c, ll x){
    return a+b+c <= x;
}

void solve(){
    ll n, x; cin >> n >> x;
    ll ans = 0;
    for(ll a = 1; a <= n-2; a++){
        for(ll b = 1; b <= n-2; b++){
            if(!eq(a, b, 1, n) or !eq2(a, b, 1, x)) break;

            ll l = 1, r = n-2, ma = 0;
            while(l <= r){
                ll c = l+(r-l)/2;
                if(eq(a, b, c, n) and eq2(a, b, c, x)) ma = c, l = c+1;
                else r = c-1;
            }
            ans += ma;
        }
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
