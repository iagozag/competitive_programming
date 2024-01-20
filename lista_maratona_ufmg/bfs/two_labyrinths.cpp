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

const int MAX = 550;

int n, m;
vector<ii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<string> grid1(MAX), grid2(MAX);
int dist[MAX][MAX];

bool val(int i, int j){
    return i >= 0 and i < n and j >= 0 and j < m and dist[i][j] == -1;
}

int bfs_both(ii s){
    memset(dist, -1, sizeof dist);
    dist[s.ff][s.ss] = 0;

    queue<ii> q; q.push(s);
    while(!q.empty()){
        ii v = q.front(); q.pop();
        for(auto [x, y]: moves){
            x += v.ff, y += v.ss;
            if(!val(x, y) or grid1[x][y] != '.' or grid2[x][y] != '.') continue;

            if(x == n-1 && y == m-1) return dist[v.ff][v.ss]+1;

            dist[x][y] = dist[v.ff][v.ss]+1;
            q.push({x, y});
        }
    }

    return -1;
}

int bfs_dist(ii s, int g){
    memset(dist, -1, sizeof dist);
    dist[s.ff][s.ss] = 0;

    queue<ii> q; q.push(s);
    while(!q.empty()){
        ii v = q.front(); q.pop();
        for(auto [x, y]: moves){
            x += v.ff, y += v.ss;
            if(!val(x, y) or (g == 1 ? grid1[x][y] : grid2[x][y]) != '.') continue;

            if(x == n-1 && y == m-1) return dist[v.ff][v.ss]+1;

            dist[x][y] = dist[v.ff][v.ss]+1;
            q.push({x, y});
        }
    }

    return 0;

}

void solve(){
    cin >> n >> m;
    rep(i, 0, n) cin >> grid1[i];
    rep(i, 0, n) cin >> grid2[i];

    int dist_b = bfs_both({0, 0});
    cout << ((dist_b == bfs_dist({0, 0}, 1) and dist_b == bfs_dist({0, 0}, 2))
             or (n == 1 and m == 1) ? "YES" : "NO") << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
