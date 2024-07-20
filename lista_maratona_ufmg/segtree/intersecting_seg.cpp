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

vi v; vi seg;

int update(int node, int l, int r, int idx){
    if(idx < l or idx > r) return seg[node];
    if(l == r) return seg[node] = -2;
    int m = (l+r)>>1;
    return seg[node] = update(node*2, l, m, idx)+update(node*2+1, m+1, r, idx);
}

int query(int node, int l, int r, int ql, int qr){
    if(ql > r or qr < l) return 0;
    if(ql <= l and r <= qr) return seg[node];
    int m = (l+r)>>1;
    return query(node*2, l, m, ql, qr)+query(node*2+1, m+1, r, ql, qr);
}

void solve(){
    int n; cin >> n;
    v = vi(2*n), seg = vi(8*n);
    for(int i = 0; i < 2*n; i++) cin >> v[i];

    vi ans(n+1); vi vis(n+1, -1);
    rep(i, 0, 2*n){
        if(vis[v[i]] != -1){
            ans[v[i]] = i-vis[v[i]]-1;
            ans[v[i]] += query(1, 0, 2*n-1, vis[v[i]]+1, i-1);
            update(1, 0, 2*n-1, vis[v[i]]);
        }
        vis[v[i]] = i;
    }

    rep(i, 1, n+1) cout << ans[i] << " ";
    cout << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

