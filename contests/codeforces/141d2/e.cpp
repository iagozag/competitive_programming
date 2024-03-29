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

void no(){ cout << "Impossible" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e2+10, MOD = 1e9+7;

int n, m;
vector<vi> g(MAX), g_t(MAX);
vector<bool> vis(MAX);
vi value(MAX), id(MAX, -1), order, ans;

// a xor b = (a or b) and (~a or ~b)
// = ~a -> b, ~b -> a, a -> ~b, b -> ~a
void xoredge(int u, int v){
    g[u^1].eb(v), g_t[v].eb(u^1);
    g[v^1].eb(u), g_t[u].eb(v^1);
    g[u].eb(v^1), g_t[v^1].eb(u);
    g[v].eb(u^1), g_t[u^1].eb(v);
}

void dfs1(int v){
    vis[v] = 1;
    forr(ve, g[v]) if(!vis[ve]) dfs1(ve);
    order.eb(v);
}

void dfs2(int v, int p){
    id[v] = p;
    forr(ve, g_t[v]) if(id[ve] == -1) dfs2(ve, p);
}

void solve(){
    cin >> n >> m;
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c; --a, --b;
        if(!c) xoredge(a<<1, b<<1);
        else xoredge(a<<1, (b<<1)^1);
    }

    rep(i, 0, 2*n) if(!vis[i]) dfs1(i);
    reverse(all(order));

    int k = 0;
    forr(x, order) if(id[x] == -1) dfs2(x, k++);

    for(int i = 0; i < 2*n; i += 2){
        if(id[i] == id[i+1]) return no();
    }

    vis = vector<bool>(MAX);
    forr(x, order){
        if(!vis[x/2]){
            vis[x/2] = 1;
            if(!(x&1)) ans.eb(x/2+1);
        }
    }

    cout << ans.size() << endl;
    forr(x, ans) cout << x << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
