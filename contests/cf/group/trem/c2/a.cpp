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
#define pb push_back
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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10;

vector<ii> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> g;
vector<vi> dist(1e3+10, vi(1e3+10));

int n, m;
bool val(int i, int j){
    return i >= 0 and i < n and j >= 0 and j < m and g[i][j] == '.';
}

void bfs(queue<ii>& q){
    while(!q.empty()){
        ii v = q.front(); q.pop();
        rep(l, 0, 4){
            int a = v.ff+moves[l].ff, b = v.ss+moves[l].ss;
            if(val(a, b) and dist[a][b] < dist[v.ff][v.ss]+1){
                dist[a][b] = dist[v.ff][v.ss]+1, g[a][b] = '#';
                q.push({a, b});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    g = vector<string>(n);
    forr(x, g) cin >> x;

    queue<ii> q;
    rep(i, 0, n) rep(j, 0, m){
        if(g[i][j] == '#') q.push({i, j});
    }

    bfs(q);

    int ans = 0;
    rep(i, 0, n) rep(j, 0, m) ans = max(ans, dist[i][j]);

    cout << ans << endl;
}

int main(){ _
    int t = 1;

    while(t--) solve();

    exit(0);
}

