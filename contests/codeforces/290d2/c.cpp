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

const int MAX = 2e5+10, MOD = 1e9+7;

vector<vi> g(26);
vi order, vis, color;

bool cyc(int v) {
    color[v] = 1;
    for (int u : g[v]) {
        if (color[u] == 0 and cyc(u)) return true;
        else if (color[u] == 1) return true;
    }
    color[v] = 2;
    return false;
}

void dfs(int v){
    vis[v] = 1;
    forr(ve, g[v]) if(!vis[ve]) dfs(ve);
    order.eb(v);
}

void solve(){
    int n; cin >> n; 
    vector<string> v(n); forr(x, v) cin >> x;

    rep(i, 0, n-1){
        int j = 0;
        while(j < v[i].size() and j < v[i+1].size() and v[i][j] == v[i+1][j]) j++;
        if(j == v[i+1].size() and v[i].size() > v[i+1].size()) return no();

        if(j < v[i].size()) 
            g[v[i][j]-'a'].eb(v[i+1][j]-'a');
    }

    vis = vi(26);
    rep(i, 0, 26) if(!vis[i]) dfs(i);
    reverse(all(order));

    color = vi(26);
    rep(i, 0, 26) if(color[i] == 0 and cyc(i)) return no(); 

    forr(x, order) cout << char(x+'a');
    cout << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
