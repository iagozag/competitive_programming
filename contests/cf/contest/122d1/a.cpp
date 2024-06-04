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

const int MAX = 60, MOD = 1e9+7;

vector<vi> g(MAX);
int n, m; vector<ii> moves{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int tim = 0;
vi tin(MAX), low(MAX);
vector<bool> vis(MAX);
int ans = 1;

void dfs(int v, int p = -1){
    vis[v] = 1, tin[v] = low[v] = tim++;

    int c = 0;
    forr(ve, g[v]){
        if(ve == p) continue;
        if(vis[ve]) low[v] = min(low[v], tin[ve]);
        else{
            dfs(ve, v);
            low[v] = min(low[v], low[ve]);
            if(low[ve] >= tin[v] and p != -1) ans++;
            c++;
        }
    }

    if(p == -1 and c > 1) ans++;
}

bool is_val(int i, int j){
    return i >= 0 and i < n and j >= 0 and j < m;
}

void solve(){
    int t = 0, sti, stj; cin >> n >> m;
    vector<vi> v(n, vi(m));
    rep(i, 0, n){
        string a; cin >> a;
        rep(j, 0, m){ if(a[j] == '#') v[i][j] = t++, sti = i, stj = j; else v[i][j] = -1; }
    }

    if(t <= 3){ cout << -1 << endl; return; }

    rep(i, 0, n) rep(j, 0, m){
        if(v[i][j] == -1) continue;
        for(auto [a, b]: moves){
            a += i, b += j;
            if(!is_val(a, b) or v[a][b] == -1) continue;
            g[v[i][j]].eb(v[a][b]), g[v[a][b]].eb(v[i][j]);
        } 
    }

    rep(i, 0, n){ dbgc(v[i]); }

    dfs(0); 
    cout << ans << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
