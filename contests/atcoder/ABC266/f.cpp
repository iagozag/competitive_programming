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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vector<vi> g;
set<int> cyc;
vi vis;
vi id;
int cs, ce;

bool dfs(int v, int p){
    vis[v] = 1;
    forr(ve, g[v]){
        if(ve == p) continue;
        if(vis[ve]){
            cs = ve, ce = v;
            return true;
        }
        id[ve] = v;
        if(dfs(ve, v)) return true;
    }
    return false;
}

void dfs2(int v, int p){
    id[v] = p;
    forr(ve, g[v]) if(!cyc.count(ve) and id[ve] != p){
        dfs2(ve, p);
    }
}

void solve(){
    int n; cin >> n;
    g.resize(n), vis.resize(n), id.resize(n);
    rep(i, 0, n){
        int a, b; cin >> a >> b; --a, --b;
        g[a].eb(b), g[b].eb(a);
    }

    dfs(0, -1);

    while(ce != cs) cyc.insert(ce), ce = id[ce];
    cyc.insert(cs);

    id = vi(n, -1);
    forr(x, cyc) dfs2(x, x);

    int q; cin >> q;
    rep(i, 0, q){
        int a, b; cin >> a >> b; --a, --b;
        if(cyc.count(a) and cyc.count(b)) cout << "No\n";
        else if(!cyc.count(a) and !cyc.count(b)) cout << (id[a] == id[b] ? "Yes\n" : "No\n");
        else if(cyc.count(a) and !cyc.count(b)) cout << (id[b] == a ? "Yes\n" : "No\n");
        else cout << (id[a] == b ? "Yes\n" : "No\n");
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
