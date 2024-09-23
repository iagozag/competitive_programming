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

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vi v(n); rep(i, 0, n){ char c; cin >> c; v[i] = (int)(c-'a'); }

    if(n == 1){ cout << 1 << endl; return; }

    int ans = INF;
    if(n&1){
        vector<vi> dp(n, vi(2));
        rep(i, 0, 26) rep(j, 0, 26){
            dp[0][0] = (v[0] != i), dp[0][1] = INF;
            dp[1][0] = dp[0][0]+(v[1] != j), dp[1][1] = 1+(v[1] != i);
            rep(k, 2, n){
                dp[k][0] = dp[k-1][0], dp[k][1] = min(dp[k-2][0]+1, dp[k-1][1]);

                if((k%2 == 0 and v[k] != i) or (k%2 and v[k] != j)) dp[k][0]++;
                if((k%2 and v[k] != i) or (k%2 == 0 and v[k] != j)) dp[k][1]++;
            }
            ckmin(ans, min(dp[n-2][0]+1, dp[n-1][1]));
        }
    } else{
        rep(i, 0, 26) rep(j, 0, 26){
            int mi = 0; 
            rep(k, 0, n)
                if((k%2 == 0 and v[k] != i) or (k%2 and v[k] != j)) mi++;
            ckmin(ans, mi);
        }
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
