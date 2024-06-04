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

vi v, seg;

int build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = v[tl];

    int tm = tl+(tr-tl)/2;
    return seg[node] = min(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

int update(int node, int tl, int tr, int idx, int val){
    if(idx < tl or idx > tr) return seg[node];
    if(tl == tr) return seg[node] = val;

    int tm = tl+(tr-tl)/2;
    return seg[node] = min(update(node*2, tl, tm, idx, val), update(node*2+1, tm+1, tr, idx, val));
}

int query(int node, int tl, int tr, int l, int r){
    if(r < tl or l > tr) return INF;
    if(l <= tl and r >= tr) return seg[node];
    
    int tm = tl+(tr-tl)/2;
    return min(query(node*2, tl, tm, l, r), query(node*2+1, tm+1, tr, l, r));
}

void solve(){
    int n, x; cin >> n >> x;
    v = vi(n), seg = vi(4*n);

    map<int, set<int>> mp;
    rep(i, 0, n) cin >> v[i], mp[v[i]].insert(i);

    build(1, 0, n-1);

    int ans = 0, money = 0;
    rep(i, 0, n){
        int mi = query(1, 0, n-1, i, n-1);
        if(money >= mi){
            auto idx = mp[mi].lower_bound(i);
            update(1, 0, n-1, *idx, INF), mp[mi].erase(*idx);
            ans++, money -= mi;
        }

        money += x;
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
