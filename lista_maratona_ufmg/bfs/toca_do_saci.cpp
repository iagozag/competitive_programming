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

const int MAX = 1e3+10;

int n, m;
vector<ii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vi> grid;
int dist[MAX][MAX];
bool vis[MAX][MAX];

bool val(int i, int j){
    return i >= 0 and i < n and j >= 0 and j < m and !vis[i][j] and grid[i][j] != 0;
}

int bfs(ii s){
    vis[s.ff][s.ss] = 1, dist[s.ff][s.ss] = 1;

    queue<ii> q; q.push(s);
    while(!q.empty()){
        ii v = q.front(); q.pop();
        for(auto [x, y]: moves){
            x += v.ff, y += v.ss;
            if(!val(x, y)) continue;

            if(grid[x][y] == 3) return dist[v.ff][v.ss]+1;

            dist[x][y] = dist[v.ff][v.ss]+1, vis[x][y] = 1;
            q.push({x, y});
        }
    }

    return 0;
}

void solve(){
    cin >> n >> m;
    grid = vector<vi>(n, vi(m));
    memset(vis, 0, sizeof vis);
    memset(dist, -1, sizeof dist);
    
    ii source;
    rep(i, 0, n) rep(j, 0, m){
        cin >> grid[i][j];
        if(grid[i][j] == 2) source = {i, j};
    }

    cout << bfs(source) << endl; 
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

