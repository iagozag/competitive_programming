#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void DBG() {
    cerr << "]" << endl;
}

void DBGC() {
    cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t)) cerr << ", ";
    DBG(t...);
}

template<class H, class... T> void DBGC(H h, T... t) {
    for(auto& x: h) cerr << x << " ";
    if(sizeof...(t)) cerr << "], [ ";
    DBGC(t...);
}

#ifndef _DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
#else
#define dbg(...) 0
#define dbgc(...) 0
#endif

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 1e6+10;

int n, m, s, e, k;
vi fun, order, c, par;
vl comp_sum, dist;
vector<vi> g, g_t, cond;
vector<bool> vis;

void dfs(int v){
    vis[v] = 1;
    forr(ve, g[v]) if(!vis[ve]) dfs(ve);
    order.eb(v);
}

void dfs2(int v, ll& sum){
    c.eb(v), vis[v] = true, sum += fun[v], par[v] = k;
    forr(ve, g_t[v]) if(!vis[ve]) dfs2(ve, sum);
}

void dfs3(int v){
    forr(ve, cond[v]){
        dist[ve] = max(dist[ve], dist[v]+comp_sum[ve]);
        dfs3(ve);
    }
}

void solve(){
    cin >> n >> m >> s >> e; --s, --e;
    g = g_t = vector<vi>(n), vis = vector<bool>(n), fun = par = vi(n);
    comp_sum = dist = vl(n); 
    iota(all(par), 0);

    rep(i, 0, n) cin >> fun[i];
    rep(i, 0, m){
        int a, b; cin >> a >> b; --a, --b;
        g[a].eb(b), g_t[b].eb(a);
    }

    rep(i, 0, n) if(!vis[i]) dfs(i);
    reverse(all(order));

    vector<vi> comp; vis = vector<bool>(n);
    forr(v, order){
        if(vis[v]) continue;

        ll sum = 0; k = v; dfs2(v, sum);
        comp.eb(c), c.clear(), comp_sum[v] = sum;
    }

    cond = vector<vi>(n);
    rep(i, 0, n){
        forr(ve, g[i]){
            if(par[i] != par[ve]) cond[par[i]].eb(par[ve]);
        }
    }

    dist[par[s]] = comp_sum[par[s]];
    dfs3(par[s]);

    cout << dist[par[e]] << endl;
}

int main(){ _
    int t = 1;

    while(t--) solve();

    exit(0);
}
