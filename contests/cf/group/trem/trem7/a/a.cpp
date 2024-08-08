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

int n;
vector<vi> g;
vector<bool> vis;
vi ans;

void dfs(int v){
    vis[v] = 1;
    forr(ve, g[v]) if(!vis[ve]) dfs(ve);
    ans.eb(v);
};

void solve(){
    cin >> n;
    g = vector<vi>(n);
    rep(i, 0, n){
        int m; cin >> m;
        rep(j, 0, m){ int a; cin >> a; --a; g[a].eb(i); }
    }

    vis = vector<bool>(n);
    rep(i, 0, n) if(!vis[i]) dfs(i);
    reverse(all(ans));

    forr(x, ans){
        if(g[x].size()) cout << x+1 << " ";
    }
    cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

