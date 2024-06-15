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

void solve(){
    int n; cin >> n;
    vector<pair<string, string>> v(n); forr(x, v) cin >> x.ff >> x.ss;

    auto cmp = [&](int a, int b) -> int{
        if(a == 0) return 0;
        pair<string, string> pss = v[b];
        rep(i, 0, n) if(a&(1<<i) and (v[b].ff == v[i].ff or v[b].ss == v[i].ss)) return 0;
        return 1;
    };

    int dp[1<<n]; memset(dp, INF, sizeof dp); dp[0] = 0;
    rep(i, 1, 1<<n){
        rep(j, 0, n) if(i&(1<<j)){
            dp[i] = min(dp[i], dp[i^(1<<j)]+cmp(i^(1<<j), j));
        } 
    }

    rep(i, 0, 1<<n) cout << bitset<16>(i).to_string() << ": " << dp[i] << endl;

    cout << dp[(1<<n)-1] << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
