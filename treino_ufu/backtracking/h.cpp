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

int n = 10;
vector<vector<char>> grid;
vector<vi> dist;

vector<ii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

bool val(int i, int j, char x){
    return i >= 0 and i < n and j >= 0 and j < n and grid[i][j] == x and dist[i][j] == -1;
}

bool bfs(int i, int j, string s){
    dist = vector<vi>(n, vi(n, -1));
    queue<ii> q; q.push({i, j}); dist[i][j] = 0;

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        
        if(dist[x][y] == s.size()-1) return 1;

        for(auto u: moves){
            u.ff+=x, u.ss += y;
            if(!val(u.ff, u.ss, s[dist[x][y]+1])) continue;
            q.push(u), dist[u.ff][u.ss] = dist[x][y]+1;
        }
    }

    return 0;
}

void solve(){
    grid = vector<vector<char>>(n, vector<char>(n));

    rep(i, 0, n) rep(j, 0, n){
        cin >> grid[i][j];
    }

    string s;
    while(cin >> s){
        bool b = 0;
        rep(i, 0, n) rep(j, 0, n) if(grid[i][j] == s[0]){
            b |= bfs(i, j, s);
            if(b) break;
        }
        cout << b << endl;
    }
}

int main(){ _
    int t = 1;

    while(t--) solve();

    exit(0);
}


