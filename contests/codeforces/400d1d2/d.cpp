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

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<vi> g(MAX), g_t(MAX);
vector<bool> vis(MAX);
vector<vi> s(MAX);
vi doors(MAX), id(MAX, -1), order;

// a xor b = (a or b) and (~a or ~b)
// = ~a -> b, ~b -> a, a -> ~b, b -> ~a
void addxor(int u, int v){
    g[u+1].eb(v), g[v+1].eb(u);
    g[u].eb(v+1), g[v].eb(u+1);

    g_t[v].eb(u+1), g_t[u].eb(v+1);
    g_t[v+1].eb(u), g_t[u+1].eb(v);
}

// a xor ~b = (a or ~b) and (~a or b)
// = ~a -> ~b, b -> a, a -> b, ~b -> ~a
void addnxor(int u, int v){
    g[u+1].eb(v+1), g[v].eb(u);
    g[u].eb(v), g[v+1].eb(u+1);

    g_t[v+1].eb(u+1), g_t[u].eb(v);
    g_t[v].eb(u), g_t[u+1].eb(v+1);
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

bool is_sat(){
    rep(i, 0, 2*m) if(!vis[i]) dfs1(i);
    reverse(all(order));

    int k = 0;
    forr(x, order) if(id[x] == -1) dfs2(x, k++);

    for(int i = 0; i < 2*m; i += 2) 
        if(id[i] == id[i+1]) return false;

    return true;
}

void solve(){
    cin >> n >> m;
    rep(i, 0, n) cin >> doors[i];
    rep(i, 0, m){
        int t; cin >> t; 
        rep(j, 0, t){ int w; cin >> w; --w; s[w].eb(i); }
    }

    rep(i, 0, n){
        int u = s[i][0], v = s[i][1];
        if(doors[i]) addnxor(u<<1, v<<1);
        else addxor(u<<1, v<<1);
    }

    if(is_sat()) return yes();
    else return no();
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}

