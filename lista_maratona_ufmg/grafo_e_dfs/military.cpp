#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
#define forr(v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
#define pb push_back

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

const int MAX = 2e5+10;

vector<vi> g(MAX);
vi child;
map<int,int> mp;

void dfs(int u, vi& vert){
    vert.pb(u), mp[u] = vert.size()-1;

    if(g[u].size() == 0) child[u] = 0;
    
    for(auto ve: g[u]){
        dfs(ve, vert);
        child[u] += child[ve]+1;
    }
}

void solve(){
    int n, q; cin >> n >> q;
    rep(i, 1, n){
        int a; cin >> a; a--;
        g[a].pb(i);
    }

    vi vert; child = vi(n);
    dfs(0, vert);
    dbgc(vert, child);

    rep(i, 0, q){
        int u, k; cin >> u >> k; u--, k--;

        cout << (k <= child[u] ? vert[mp[u]+k]+1 : -1) <<endl;
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
