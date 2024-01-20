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

int MAX = 1e5+10;
vector<vi> g(MAX);
vector<bool> vis(MAX);
vi id(MAX, -1);

void bfs(int x){
    vis[x] = 1, id[x] = x;

    queue<int> q; q.push(x);
    while(!q.empty()){
        int v = q.front(); q.pop();

        for(auto& ve: g[v]) if(!vis[ve]){
            id[ve] = v, q.push(ve);
            vis[ve] = 1;
        }
    }
}

vi vi_ans(int x){
    vi ans = {x};
    while(id[x] != x){
        x = id[x];
        ans.pb(x);
    }
    reverse(all(ans));

    return ans;
}

void solve(){
    int n, m; cin >> n >> m;

    rep(i, 0, m){
        int a, b; cin >> a >> b; a--, b--;
        g[a].pb(b), g[b].pb(a);
    }

    bfs(0);

    if(id[n-1] == -1){ cout << "IMPOSSIBLE\n"; return; }
    
    vi ans = vi_ans(n-1);
    cout << ans.size() << endl;
    forr(ans) cout << x+1 << " ";
    cout << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

