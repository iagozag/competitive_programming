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

int l, c; const int MAX = 110;
vector<ii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<string> grid(MAX);
bool vis[MAX][MAX];

bool valid(int i, int j){
    return !(i < 0 || i >= l || j < 0 || j >= c || vis[i][j] || grid[i][j] == '.');
}

ii bfs(ii beg){
    vis[beg.ff][beg.ss] = 1;

    queue<ii> q; q.push(beg); ii ans;
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(auto u: moves){
            u.ff += x, u.ss += y;
            if(!valid(u.ff, u.ss)) continue;

            vis[u.ff][u.ss] = 1;
            q.push({u.ff, u.ss}), ans = {u.ff, u.ss};
        }
    }

    return ans;
}

void solve(){
    cin >> l >> c;
    rep(i, 0, l) cin >> grid[i];

    ii idx;
    rep(i, 0, l) rep(j, 0, c) 
        if(grid[i][j] == 'o') idx = {i, j};

    ii ans = bfs(idx);
    cout << ans.ff+1 << " " << ans.ss+1 << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

