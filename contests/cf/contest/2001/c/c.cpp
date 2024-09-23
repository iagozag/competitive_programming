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

vi vis;
vector<pii> edges;

int query(int a, int b){
    cout << "? " << a << " " << b << endl;
    int q; cin >> q; return q;
}

void divide(int a, int b){
    if(vis[a] and vis[b]) return;
    int q = query(a, b);
    if(q == a or q == b){
        vis[a] = vis[b] = 1;
        edges.eb(a, b);
        return;
    }
    divide(a, q), divide(q, b);
}

void solve(){
    int n; cin >> n;
    vis = vi(n+1), edges.clear();

    rep(i, 2, n+1){
        if(!vis[1] or !vis[i]) divide(1, i);
    }

    cout << "! ";
    forr(x, edges) cout << x.ff << " " << x.ss << " ";
    cout << endl;
}

int main(){ // _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
