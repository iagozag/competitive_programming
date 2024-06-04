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

const int MAX = 1e3+10;

int n, m;
vector<vi> g;
vector<vi> dist;

bool bfs(vector<ii> sources){
    queue<ii> q; forr(x, sources) q.push(x);
    q.push({0,0}), dist[0][0] = 0;

    while(!q.empty()){
        auto[x, y] = q.front(); q.pop();

        if(x == n-1 and y == m-1) return true;

        if(g[x][y] == 1){
            int new_x = x-1 >= 0 ? x-1 : n-1;
            g[new_x][y] = 1, g[x][y] = 0;
            q.push({new_x, y});
        } else{
            int new_x = x-1 >= 0 ? x-1 : n-1;
            if(dist[new_x][y] != INF) 
                q.push({new_x, y}), g[new_x][y] = 2, dist[new_x][y] = min(dist[new_x][y], dist[x][y]+1);
            
            if(y+1 <= m-1 and g[x][y+1] != 1){
                if(dist[x][y+1] != INF)
                    q.push({x, y+1}), dist[x][y+1] = min(dist[x][y+1], dist[x][y]+1), g[x][y+1] = 2;
            }

            if(g[x][y] == 2){
                new_x = x+1 <= n-1 ? x+1 : 0;
                if(dist[new_x][y] != INF) 
                    q.push({new_x, y}), dist[new_x][y] = min(dist[new_x][y], dist[x][y]+1), g[new_x][y] = 2;
            } 
        }
    }

    return false;
}

void solve(){
    cin >> n >> m;
    g = vector<vi>(n, vi(m));
    dist = vector<vi>(n, vi(m, INF)); 

    vector<ii> sources;
    rep(i, 0, n) rep(j, 0, m){ cin >> g[i][j]; if(g[i][j]) sources.eb(i, j); }
    g[0][0] = 2;

    cout << (bfs(sources) ? dist[n-1][m-1] : -1) << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
