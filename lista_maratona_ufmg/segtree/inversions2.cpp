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
vi v, seg;

int build(int node, int l, int r){
    if(l == r) return seg[node] = 1;
    int m = (l+r)/2;
    return seg[node] = build(node*2, l, m)+build(node*2+1, m+1, r);
}

int update(int node, int l, int r, int idx){
    if(idx < l or idx > r) return seg[node];
    if(l == r) return seg[node] = 0;
    int m = (l+r)/2;
    return seg[node] = update(node*2, l, m, idx)+update(node*2+1, m+1, r, idx);
}

int query(int node, int l, int r, int val){
    if(l == r) return l; 
    int m = (l+r)>>1;
    if(seg[node*2] >= val) return query(node*2, l, m, val);
    else return query(node*2+1, m+1, r, val-seg[node*2]);
}

void solve(){
    cin >> n; v = vi(n), seg = vi(4*MAX);
    forr(x, v) cin >> x;

    build(1, 0, n-1);

    reverse(all(v));
    vi ans(n);
    rep(i, 0, n){
        ans[i] = query(1, 0, n-1, n-v[i]-i)+1;
        update(1, 0, n-1, ans[i]-1);
    }
    reverse(all(ans));
    forr(x, ans) cout << x << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
