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

struct ed{
    int a, b; ll s, t; 
    ed(int _a, int _b, ll _s, ll _t): a(_a), b(_b), s(_s), t(_t){}
};

struct ev{
    ll p; int t, id;
    ev(ll _p, int _t, int _id): p(_p), t(_t), id(_id){}
};

void solve(){
    int n, m; ll x; cin >> n >> m >> x;

    vector<ed> edges; vector<ev> events;
    
    rep(i, 0, m){
        int a, b; ll s, t; cin >> a >> b >> s >> t; --a, --b;
        edges.eb(a, b, s, t);
        events.eb(s, 1, i), events.eb(t, 0, i);
    }
    sort(all(events), [&](ev a, ev b){
        if(a.p != b.p) return a.p < b.p;
        return a.t < b.t;
    });

    vl ans(m), time(n); 
    ans[0] = x;

    rep(i, 0, 2*m){
        auto [p, t, id] = events[i];
        if(t) ckmax(ans[id], time[edges[id].a]-p);
        else ckmax(time[edges[id].b], ans[id]+p);
    }

    rep(i, 1, m) cout << ans[i] << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
