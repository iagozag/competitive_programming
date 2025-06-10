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

void no(){ cout << "IMPOSSIBLE" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<vi> g, g_t;
vector<bool> vis;
vi id, order;

void addedge(int a, int b){
    g[a^1].eb(b), g[b^1].eb(a);
    g_t[b].eb(a^1), g_t[a].eb(b^1);
}

void dfs1(int v){
    vis[v] = 1;
    forr(ve, g[v]) if(!vis[ve]) dfs1(ve);
    order.eb(v);
}

void dfs2(int v, int p){
    id[v] = p;
    forr(ve, g_t[v]) if(id[ve] == -1) dfs2(ve, p);
}

void solve(){
    cin >> n >> m; 
    g = g_t = vector<vi>(2*m); vis = vector<bool>(m*2), id = vi(m*2, -1);
    rep(i, 0, n){
        int a, b; char c, d; cin >> c >> a >> d >> b; --a, --b;
        if(c == '+' and d == '+') addedge(a<<1, b<<1);
        else if(c == '-' and d == '+') addedge((a<<1)^1, b<<1);
        else if(c == '+' and d == '-') addedge(a<<1, (b<<1)^1);
        else addedge((a<<1)^1, (b<<1)^1);
    }

    rep(i, 0, 2*m) if(!vis[i]) dfs1(i);
    reverse(all(order));
    
    int k = 0;
    forr(x, order) if(id[x] == -1) dfs2(x, k++);
    
    vi values(m);
    for(int i = 0; i < 2*m; i += 2){
        if(id[i] == id[i+1]) return no();
        values[i/2] = id[i] > id[i+1];
    }

    forr(x, values) cout << (x ? '+' : '-') << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
