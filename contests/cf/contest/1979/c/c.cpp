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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "-1" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    ll n; cin >> n;
    vector<pll> v(n); rep(i, 0, n){ ll a; cin >> a; v[i] = {a, i}; }
    sort(all(v), greater<pll>());

    vl ans(n, 1e9); ll coins = n*1e9;
    ll mi = v[n-1].ff*1e9;

    rep(i, 0, n-1){
        ans[i] = (mi+v[i].ff-1)/v[i].ff;
        coins -= (1e9-ans[i]);
    }

    rep(i, 0, n){
        if(v[i].ff*ans[i] <= coins) return no();
    }

    vl anss(n);
    rep(i, 0, n){
        anss[v[i].ss] = ans[i];
    }

    forr(x, anss) cout << x << ' ';
    cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
