#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
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

void no(){ cout << "-1" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, sum = 0; cin >> n;
    vi v(n); forr(x, v) cin >> x, sum += x;

    if(sum&1) return no();

    vi dp(sum/2+1), par(sum/2+1, -1); dp[0] = 1;
    rep(i, 0, n) per(j, sum/2, v[i]) if(dp[j-v[i]]){
        dp[j] = 1;
        if(par[j] == -1) par[j] = i;
    }

    if(!dp[sum/2]) return no();

    vi alice, bob;
    int p = sum/2;
    while(p) alice.eb(par[p]), p -= v[par[p]];
    sort(all(alice));
    rep(i, 0, n){
        int lb = lower_bound(all(alice), i)-alice.begin();
        if(lb >= sz(alice) or alice[lb] != i) bob.eb(i);
    }

    vi ans;
    int a = 0, b = 0, i = 0, j = 0;
    while(i < sz(alice) or j < sz(bob)){
        if(a <= b) ans.eb(v[alice[i++]]), a += ans.back();
        else ans.eb(v[bob[j++]]), b += ans.back();
    }

    rep(k, 0, n) cout << ans[k] << " \n"[k==n-1];
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
