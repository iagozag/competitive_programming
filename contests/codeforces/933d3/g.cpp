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

const int MAX = 2e5+10;

vector<int> dist;
vector<vi> g;

int bfs(int s, int d){
    queue<int> q; q.push(s), dist[s] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();

        forr(ve, g[v]) if(dist[ve] == -1){
            dist[ve] = dist[v]+1, q.push(ve);
        }
    }

    return dist[d]/2;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m); set<int> cl;
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c; a--, b--;
        edges[i] = {a, b, c}, cl.insert(c); 
    }

    int so, d; cin >> so >> d; so--, d--;

    vi colors(all(cl));
    g = vector<vi>(n+colors.size());
    for(auto& [x, y, z]: edges){
        int idx = lower_bound(all(colors), z)-colors.begin();
        g[x].eb(n+idx), g[n+idx].eb(x), g[y].eb(n+idx), g[n+idx].eb(y);
    }

    dist = vi(n+colors.size(), -1);
    cout << bfs(so, d) << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
