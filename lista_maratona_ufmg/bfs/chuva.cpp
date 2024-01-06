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

int n, m;
vector<ii> moves = {{0, -1}, {0, 1}};
vector<string> grid;

bool val(int i, int j){
    return j >= 0 and j < m and grid[i][j] == '.';
}

void bfs(ii s){
    queue<ii> q; q.push(s);
    while(!q.empty()){
        ii v = q.front(); q.pop();
        if(v.ff == n-1) continue;

        if(grid[v.ff+1][v.ss] == '.'){
            grid[v.ff+1][v.ss] = 'o';
            q.push({v.ff+1, v.ss});
            continue;
        }

        if(grid[v.ff+1][v.ss] != '#') continue;

        for(auto [x, y]: moves){
            x += v.ff, y += v.ss;
            if(!val(x, y)) continue;

            grid[x][y] = 'o';
            q.push({x, y});
        }
    }
}

void solve(){
    cin >> n >> m;
    grid = vector<string>(n);
    rep(i, 0, n) cin >> grid[i];

    ii idx;
    rep(i, 0, m) if(grid[0][i] == 'o'){
        idx = {0, i}; break; 
    }
    
    bfs(idx);

    forr(grid) cout << x << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
