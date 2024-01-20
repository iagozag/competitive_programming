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

vector<ii> moves = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
int grid[8][8];
int dist[8][8];

bool val(int i, int j){
    return i >= 0 and i < 8 and j >= 0 and j < 8 and dist[i][j] == -1;
}

int bfs(ii s){
    dist[s.ff][s.ss] = 0;

    queue<ii> q; q.push(s);
    while(!q.empty()){
        ii v = q.front(); q.pop();
        for(auto [x, y]: moves){
            x += v.ff, y += v.ss;
            if(!val(x, y)) continue;

            if(grid[x][y] == 1) return dist[v.ff][v.ss]+1;

            dist[x][y] = dist[v.ff][v.ss]+1;
            q.push({x, y});
        }
    }

    return 0;
}

void solve(){
    char s1, s2, f1, f2; cin >> s1 >> s2 >> f1 >> f2;
    memset(grid, 0, sizeof grid);
    memset(dist, -1, sizeof dist);
    grid[f1-'a'][(f2-'0')-1] = 1;

    cout << bfs({s1-'a', (s2-'0')-1}) << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

