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
    ll h, w, k; cin >> h >> w >> k;
    ll si, sj; cin >> si >> sj; --si, --sj;
    ll mat[h][w]; rep(i, 0, h) rep(j, 0, w) cin >> mat[i][j];

    vector<vector<vl>> dp(min(k, h*w)+1, vector<vl>(h, vl(w, -LINF)));
    vector<pii> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    auto val = [&](int a, int b) -> bool{
        return a >= 0 and a < h and b >= 0 and b < w;
    };

    dp[0][si][sj] = 0;
    rep(t, 0, min(k, h*w)) rep(i, 0, h) rep(j, 0, w)
        for(auto [x, y]: moves){
            x += i, y += j;
            if(!val(x, y)) continue;
            dp[t+1][x][y] = max(dp[t+1][x][y], dp[t][i][j]+mat[x][y]);
        }

    ll ans = 0;
    rep(t, 0, min(k, h*w)+1) rep(i, 0, h) rep(j, 0, w) ans = max(ans, dp[t][i][j]+(k-t)*mat[i][j]);
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
