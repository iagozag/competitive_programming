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
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size(); a = " "+a, b = " "+b;

    int dp[n+1][m+1]; memset(dp, 0, sizeof dp);
    rep(i, 1, n+1) rep(j, 1, m+1){
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        if(a[i] == b[j]) ckmax(dp[i][j], dp[i-1][j-1]+1);
    }

    string ans = "";
    int i = n, j = m;
    while(i > 0 and j > 0){
        while(i > 0 and dp[i][j] == dp[i-1][j]) i--;
        while(j > 0 and dp[i][j] == dp[i][j-1]) j--;
        if(i > 0 and j > 0) ans += a[i], i--, j--;
    }

    reverse(all(ans));
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
