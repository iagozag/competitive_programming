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

void no(){ cout << "IMPOSSIBLE" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 1e5+10, MOD = 1e9+7;

int n, m;
vector<vi> g, g_t;
vi dist, vis, order, par;

void dfs1(int v){
    vis[v] = 1;
    forr(ve, g[v]) if(!vis[ve]) dfs1(ve);
    order.eb(v);
}

void solve(){
    cin >> n >> m;
    g = g_t = vector<vi>(n), dist = vi(n, -1), vis = par = vi(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b; --a, --b;
        g[a].eb(b), g_t[b].eb(a);
    }

    dfs1(0), reverse(all(order));
    dist[0] = 1;
    forr(x, order){
        if(dist[x] == -1) continue;
        forr(ve, g[x])
            if(dist[x]+1 > dist[ve]) dist[ve] = dist[x]+1, par[ve] = x;
    }

    if(dist[n-1] == -1) return no();

    stack<int> ans; int u = n-1;
    while(par[u] != u) ans.push(u+1), u = par[u];
    ans.push(1);

    cout << dist[n-1] << endl;
    while(!ans.empty()) cout << ans.top() << " ", ans.pop();
    cout << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
