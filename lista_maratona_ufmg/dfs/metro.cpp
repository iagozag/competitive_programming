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

int MAX = 2*1e4+10, ans = -1, vert;
vector<vi> g(MAX);
vi dist(MAX, -1); 

void visit_center(int x){
    dist[x] = -2;

    for(auto& ve: g[x]) if(dist[ve] == -1){
        if(g[ve].size() >= 3){ vert = ve; continue; }
        visit_center(ve);
    }
}

void dfs(int x, int prev){
    for(auto& ve: g[x]){
        if(dist[ve] == -1){
            dist[ve] = dist[x]+1;
            dfs(ve, x);
        } else if(dist[ve] == 0 and ve != prev){
            ans = dist[x]+1; 
            return;
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b; a--, b--;

        g[a].pb(b);
        g[b].pb(a);
    }

    int center;
    for(int i = 0; i < n; i++) if(g[i].size() >= 5){ center = i; break; }
    visit_center(center);

    dist[vert] = 0;
    dfs(vert, -1);

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    return(0);
}
