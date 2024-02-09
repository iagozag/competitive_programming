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

int n, m, a, b;
vector<vi> g(MAX);
vector<vi> par(MAX);
vi dist(MAX, -1);
unordered_set<int> s;

int bfs(int x){
    dist[x] = 0, par[x].pb(x);

    int v;
    queue<int> q; q.push(x);
    while(!q.empty()){
        v = q.front(); q.pop();

        if(v == a or v == b) break;

        for(auto ve: g[v]){
            if(dist[ve] == -1){
                dist[ve] = dist[v]+1, par[ve].pb(v);
                q.push(ve);
            }
            else if(dist[v] == dist[par[ve][0]]) par[ve].pb(v);
        }
    }

    return dist[v];
}

int bfs2(int obj){
    queue<int> q;
    forr(s) q.push(x), dist[x] = 0;

    while(!q.empty()){
        int v = q.front(); q.pop();
        if(v == obj) break;

        for(auto ve: g[v])
            if(dist[ve] == INF) dist[ve] = min(dist[ve], dist[v]+1), q.push(ve);
    }

    return dist[obj];
}

void make_path(int source){
    queue<int> q; q.push(source), s.insert(source);
    int v = q.front();
    while(!q.empty()){
        v = q.front(); q.pop();

        for(auto ve: par[v])
            if(!s.count(ve)) s.insert(ve), q.push(ve);
    }
}

void solve(){
    cin >> n >> m >> a >> b;
    rep(i, 0, m){
        int va, vb; cin >> va >> vb;
        g[va].pb(vb);
    }

    int ans = bfs(0); int source = (ans == dist[a] ? a : b);
    
    make_path(source);

    fill(all(dist), INF);
    cout << ans + bfs2(source == a ? b : a) << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
