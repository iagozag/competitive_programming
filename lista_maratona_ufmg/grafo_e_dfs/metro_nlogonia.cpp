#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;++i)
#define repr(i,n,x) for(int i=n;i>=x;--i)
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

const int MAX = 1e5+10;

int find_mid(vector<vi>& g, int n){
    vi dist(n, -1), par(n, -1);

    function<void(int)> bfs;
    bfs = [&](int x) -> void {
        queue<int> q; q.push(x);
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(auto ve: g[v]) if(dist[ve] == -1){
                dist[ve] = dist[v]+1, par[ve] = v;
                q.push(ve);
            }
        }
    };

    dist[0] = 0, par[0] = 0;
    bfs(0);

    int idx = 0;
    rep(i, 1, n) if(dist[idx] < dist[i]) idx = i;

    fill(all(dist), -1);
    dist[idx] = 0, par[idx] = idx;
    bfs(idx);

    idx = 0;
    rep(i, 1, n) if(dist[idx] < dist[i]) idx = i;

    if(!(dist[idx]&1)){
        rep(i, 0, dist[idx]/2+1)
            idx = par[idx];

        return idx+1;
    } else{
        ii idxs = {idx, -1};
        rep(i, 0, dist[idx]/2)
            idxs.ff = par[idxs.ff];
        idxs.ss = par[idxs.ff];

        fill(all(dist), -1);
        dist[0] = 0, par[0] = 0;
        bfs(0);
        if(dist[idxs.ff] > dist[idxs.ss]) return idxs.ff+1;
        return idxs.ss+1;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> sq(m), ci(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b; --a, --b;
        ci[a].pb(b), ci[b].pb(a);
    }
    rep(i, 0, m-1){
        int a, b; cin >> a >> b; --a, --b;
        sq[a].pb(b), sq[b].pb(a);
    }

    cout << find_mid(ci, n) << " " << find_mid(sq, m) << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
