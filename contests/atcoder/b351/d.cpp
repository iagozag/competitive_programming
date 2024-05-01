#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
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

#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 1e3+10, MOD = 1e9+7;

vector<ii> adj = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
string v[MAX];
vector<vector<bool>> vis(MAX, vector<bool>(MAX));
set<ii> mags;

bool val(int i, int j){
    return i >= 0 and i < n and j >= 0 and j < m and !vis[i][j];
}

bool mag(int i, int j){
    return val(i, j) and v[i][j] == '#';
}

int bfs(ii s){
    queue<ii> q; q.push(s); vis[s.ff][s.ss] = 1;
    int ans = 1;

    set<ii> mags_vis;

    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();

        for(auto x: adj){
            x.ff += i, x.ss += j;
            if(!val(x.ff, x.ss)) continue;

            if(!mags_vis.count(x) and mags.count(x)) ans++, mags_vis.insert(x);
            else if(!mags.count(x)) vis[x.ff][x.ss] = 1, ans++, q.push(x);
        }
    }

    return ans;
}

void solve(){
    cin >> n >> m;
    rep(i, 0, n) cin >> v[i];

    rep(i, 0, n) rep(j, 0, m){
        if(v[i][j] == '#') continue;

        bool has_mag = false;
        forr(x, adj) if(mag(i+x.ff, j+x.ss)) has_mag = 1;
        if(has_mag) mags.insert({i, j});
    }

    int ma = 1;
    rep(i, 0, n) rep(j, 0, m){
        if(v[i][j] == '#' or mags.count({i, j})) continue;

        if(!vis[i][j]) ma = max(ma, bfs({i, j}));
    }

    cout << ma << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
