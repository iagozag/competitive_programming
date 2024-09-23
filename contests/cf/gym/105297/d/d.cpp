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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

long double x, y, z, tx, ty, tz, r, eps = 1e-12;

long double dist(long double a, long double b, long double c){
    return sqrt((tx-a)*(tx-a)+(ty-b)*(ty-b)+(tz-c)*(tz-c));
}

bool good(long double m){
    vector<tuple<long double, long double, long double>> pos;
    rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, 2)
        pos.eb(i ? m : x-m, j ? m : y-m, k ? m : z-m);

    forr(p, pos){
        auto [px, py, pz] = p;
        if(dist(px, py, pz)-(r+m) > eps) return true;
    }
    return false;
}

void solve(){
    cin >> x >> y >> z >> tx >> ty >> tx >> r; 
    long double l = 0, ri = min({x/2.0, y/2.0, z/2.0}), ans = l;
    rep(i, 0, 400){
        long double m = (l+ri)/2.0;
        if(good(m)) ans = m, l = m;
        else ri = m;
    }

    cout << fixed << setprecision(15) << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
