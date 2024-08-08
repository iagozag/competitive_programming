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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vl v(MAX, INF);

void solve(){
    int l, r, tmp; cin >> l >> r;
    ll ans = 0; tmp = l;
    while(tmp) ans += 2, tmp /= 3;

    l++;
    int idxl = lower_bound(all(v), l)-v.begin();
    if(v[idxl] != l) idxl--;
    int idxr = lower_bound(all(v), r)-v.begin();
    if(v[idxr] != r) idxr--;

    while(idxl < idxr) ans += (v[idxl+1]-l)*idxl, l = v[++idxl]; 
    if(idxl == idxr) ans += (r-l+1)*idxl;
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    v[0] = 0, v[1] = 1;
    for(int i = 2; i <= 15; i++) v[i] = v[i-1]*3;

    while(ttt--) solve();

    exit(0);
}
