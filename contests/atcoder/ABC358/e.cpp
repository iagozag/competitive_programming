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

const int MAX = 2e5+10, MOD = 998244353;

void solve(){
    int k; cin >> k;
    vi v(26); rep(i, 0, 26) cin >> v[i];
    
    vector<vector<pair<int, vi>>> dp(k+1, vector<pair<int, vi>>(26, {0, v}));
    rep(i, 0, 26){
        if(v[i]){
            v[i]--;
            dp[1][i] = {1, v};
            v[i]++;
        } else{
            dp[1][i] = {0, v};
        }
    }

    rep(i, 1, k){
        rep(j, 0, 26){
            vi tmp = dp[i][j].ss;
            rep(l, 0, 26){
                if(tmp[l]){
                    tmp[l]--;
                    dp[i+1][l] = {(dp[i+1][l].ff+dp[i][j].ff)%MOD, tmp};
                    tmp[l]++;
                }
            }
        }
    }

    ll ans = 0;
    rep(i, 0, k+1) rep(j, 0, 26) ans += dp[i][j].ff, ans %= MOD;
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
