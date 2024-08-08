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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int n;
vector<vi> g;
vi vis;
ordered_set st;
ll ans = 0;

void dfs(int v){
    vis[v] = 1, st.insert(v), ans += st.size()-(st.order_of_key(v)+1);
    forr(ve, g[v]) if(!vis[ve]){
        dfs(ve);
    }
    st.erase(v);
}

void solve(){
    cin >> n;
    g = vector<vi>(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b; --a, --b;
        g[a].eb(b), g[b].eb(a);
    }

    vis = vi(n);
    dfs(0);
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
