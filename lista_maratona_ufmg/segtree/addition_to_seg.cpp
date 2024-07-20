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

vl seg;

ll update(int node, int l, int r, int ul, int ur, int val){
    if(ul > r or ur < l) return 0;
    if(ul <= l and r <= ur) return seg[node] += val;
    int m = (l+r)>>1;
    return update(node*2, l, m, ul, ur, val)+update(node*2+1, m+1, r, ul, ur, val);
}

ll query(int node, int l, int r, int idx){
    if(l == r) return seg[node];

    int m = (l+r)>>1;
    return seg[node]+((l <= idx and idx <= m) ? query(node*2, l, m, idx) : query(node*2+1, m+1, r, idx));
}

void solve(){
    int n, m; cin >> n >> m;
    seg = vl(4*n);

    rep(i, 0, m){
        int q; cin >> q;
        if(q == 1){
            int l, r, val; cin >> l >> r >> val;
            update(1, 0, n-1, l, r-1, val);
        } else{
            int idx; cin >> idx;
            cout << query(1, 0, n-1, idx) << endl;
        }
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
