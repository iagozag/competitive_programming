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

int n, m; const int MAX = 1e3+10;
vector<ii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<string> grid;
bool vis[MAX][MAX];
int dist[MAX][MAX];

bool valid_idx(int i, int j){
    return i >= 0 and i < n and j >= 0 and j < m;
}

bool valid_ms(int i, int j){
    return valid_idx(i, j) and !vis[i][j] and grid[i][j] != '#';
}

void bfs_ms(vector<ii> sources){
    queue<ii> q;
    forr(sources) dist[x.ff][x.ss] = 0, vis[x.ff][x.ss] = 1, q.push(x);

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(auto u: moves){
            u.ff += x, u.ss += y;
            if(!valid_ms(u.ff, u.ss)) continue;

            dist[u.ff][u.ss] = min(dist[u.ff][u.ss], dist[x][y]+1);
            vis[u.ff][u.ss] = 1;

            q.push({u.ff, u.ss});
        }
    }
}

int bfs_ss(ii beg){
    vis[beg.ff][beg.ss] = 1, dist[beg.ff][beg.ss] = 0;

    queue<ii> q; q.push(beg);
    while(!q.empty()){
        ii v = q.front(); q.pop();
        for(auto u: moves){
            u.ff += v.ff, u.ss += v.ss;
            if(!valid_idx(u.ff, u.ss)) return dist[v.ff][v.ss]+1;

            if(vis[u.ff][u.ss] || grid[u.ff][u.ss] == '#' || dist[v.ff][v.ss]+1 >= dist[u.ff][u.ss]) continue;

            dist[u.ff][u.ss] = min(dist[u.ff][u.ss], dist[v.ff][v.ss]+1);
            vis[u.ff][u.ss] = 1;
            q.push({u.ff, u.ss});
        }
    }

    return 0;
}

void solve(){
    cin >> m >> n;
    grid = vector<string>(n);
    memset(vis, 0, sizeof vis);
    memset(dist, INF, sizeof dist);

    forr(grid) cin >> x;

    vector<ii> fires; ii start;
    rep(i, 0, n) rep(j, 0, m){
        if(grid[i][j] == '*') fires.pb({i, j});
        else if(grid[i][j] == '@') start = {i, j};
    }

    bfs_ms(fires);

    memset(vis, 0, sizeof vis);
    int ans = bfs_ss(start);

    if(ans) cout << ans;
    else cout << "IMPOSSIBLE";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
