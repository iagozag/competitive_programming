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
vl v;
vector<vl> seg;

vl combine(vl a, vl b){
    if(a[2]%2 == 0) return {a[0]+b[0], a[1]+b[1], a[2]+b[2]};
    return {a[0]+b[1], a[1]+b[0], a[2]+b[2]};
}

vl build(int node, int l, int r){
    if(l == r) return seg[node] = {v[l], 0LL, 1};
    int m = (l+r)>>1;
    return seg[node] = combine(build(node*2, l, m), build(node*2+1, m+1, r));
}

vl update(int node, int l, int r, int idx, int val){
    if(idx < l or idx > r) return seg[node];
    if(l == r) return seg[node] = {val, 0LL, 1};
    int m = (l+r)>>1;
    return seg[node] = combine(update(node*2, l, m, idx, val), update(node*2+1, m+1, r, idx, val));
}

vl query(int node, int l, int r, int ql, int qr){
    if(qr < l or ql > r) return {0LL, 0LL, 0};
    if(ql <= l and r <= qr) return seg[node];
    int m = (l+r)>>1;
    return combine(query(node*2, l, m, ql, qr), query(node*2+1, m+1, r, ql, qr));
}

void solve(){
    cin >> n; v = vl(n), seg = vector<vl>(4*n, vl(3));
    forr(x, v) cin >> x;

    build(1, 0, n-1);

    int m; cin >> m;
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c; --b;
        if(a == 0){
            update(1, 0, n-1, b, c);
        } else{
            --c;
            vl ans = query(1, 0, n-1, b, c);
            cout << ans[0]-ans[1] << endl;
        }
    }

}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
