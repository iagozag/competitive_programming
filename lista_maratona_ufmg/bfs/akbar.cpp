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

const int MAX = 1e6+10;

int n;
vector<vi> g;
int st[MAX], par[MAX];
bool guards[MAX];

int bfs(vi s){
    queue<int> q; int tot = 0;
    forr(s){
        guards[x] = 1, par[x] = x, tot++;
        if(st[x] > 0) q.push(x);
    }

    while(!q.empty()){
        int v = q.front(); q.pop();
        if(!st[v]) break;

        for(auto ve: g[v]){
            if(par[ve] == par[v]) continue;
            
            if(guards[ve]) return -1;

            guards[ve] = 1, st[ve] = st[v]-1, par[ve] = par[v], tot++;
            q.push(ve);
        }
    }

    return tot;
}

void solve(){
    int r, m; scanf("%d%d%d", &n, &r, &m); 
    g = vector<vi>(n);
    memset(guards, 0, sizeof guards);
    memset(par, -1, sizeof par);
    memset(st, -1, sizeof st);

    rep(i, 0, r){
        int a, b; scanf("%d%d", &a, &b); a--, b--;
        g[a].pb(b), g[b].pb(a);
    }

    vi sources;
    rep(i, 0, m){
        int a, b; scanf("%d%d", &a, &b); a--;
        st[a] = b, sources.pb(a);
    }

    cout << (bfs(sources) == n ? "Yes" : "No") << endl;
}

int main(){ // _
    int t; scanf("%d", &t);
    while(t--){
        solve();
    }

    exit(0);
}
