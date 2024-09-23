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
    int n, m; cin >> n >> m;

    vector<vl> edges(m);
    vector<vl> dp(n, vl(n, LINF)); rep(i, 0, n) dp[i][i] = 0;
    rep(i, 0, m){
        int a, b; ll t; cin >> a >> b >> t; --a, --b;
        edges[i] = {a, b, t};
        ckmin(dp[a][b], t), ckmin(dp[b][a], t);
    }

    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) ckmin(dp[i][j], dp[i][k]+dp[k][j]); 

    int q; cin >> q;
    rep(i, 0, q){
        int k; cin >> k; vi v;
        rep(j, 0, k){ int a; cin >> a; v.eb(a-1); }

        ll ans = LINF;
        do{
            rep(j, 0, 1<<k){
                int now = 0; ll sum = 0;
                rep(l, 0, k){
                    if(j&(1<<l))
                        sum += dp[now][edges[v[l]][0]] + edges[v[l]][2],
                        now = edges[v[l]][1];
                    else
                        sum += dp[now][edges[v[l]][1]] + edges[v[l]][2],
                        now = edges[v[l]][0];
                }
                sum += dp[now][n-1];
                ckmin(ans, sum);
            }
        } while(next_permutation(all(v)));

        cout << ans << endl;
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
