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

int m;
vector<vi> g, g_t;
vi vis, id, order;

void addedge(int a, int b){
    g[a^1].eb(b), g[b^1].eb(a);
    g_t[b].eb(a^1), g_t[a].eb(b^1);
}

void top(int v){
    vis[v] = 1;
    forr(ve, g[v]) if(!vis[ve]) top(ve);
    order.eb(v);
}

void dsu(int v, int k){
    id[v] = k;
    forr(ve, g_t[v]) if(id[ve] == -1) dsu(ve, k);
}

void solve(){
    cin >> m;
    g = g_t = vector<vi>(2*m), vis = vi(2*m), id = vi(2*m, -1), order.clear();

    vector<vi> mat(3, vi(m));
    rep(i, 0, 3) rep(j, 0, m){
        cin >> mat[i][j], 
        mat[i][j] <<= 1;
        if(mat[i][j] < 0) mat[i][j] = (-mat[i][j])^1;
        mat[i][j] -= 2;
    }

    rep(j, 0, m) rep(i, 0, 3) rep(k, i+1, 3)
        addedge(mat[i][j], mat[k][j]);     

    rep(i, 0, 2*m) if(!vis[i]) top(i);
    reverse(all(order));

    int k = 0;
    forr(x, order) if(id[x] == -1) dsu(x, k++);

    for(int i = 0; i < 2*m; i += 2) if(id[i] == id[i^1]) 
        return no();
    
    return yes();
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
