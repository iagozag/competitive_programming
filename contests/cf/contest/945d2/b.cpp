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

const int MAX = 1e5+10, MOD = 1e9+7;

int n;
vi seg, v;

int build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = v[tl];

    int tm = tl+(tr-tl)/2;
    return seg[node] = (build(node*2, tl, tm) | build(node*2+1, tm+1, tr));
}

int query(int node, int tl, int tr, int l, int r){
    if(tl > r or tr < l) return 0;
    if(l <= tl and r >= tr) return seg[node];

    int tm = tl+(tr-tl)/2;
    return (query(node*2, tl, tm, l, r) | query(node*2+1, tm+1, tr, l, r));
}

bool good(int x){
    int ans = query(1, 0, n-1, 0, x-1);
    rep(i, 1, n){
        if(i+x-1 >= n) break;
        if(query(1, 0, n-1, i, i+x-1) != ans) return false;
    }
    return true;
}

void solve(){
    cin >> n;
    v = vi(n), seg = vi(4*n); forr(x, v) cin >> x;

    build(1, 0, n-1);
    
    int l = 1, r = n, ans = n;
    while(l <= r){
        int m = l+(r-l)/2;
        if(good(m)) ans = m, r = m-1;
        else l = m+1;
    }
    
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
