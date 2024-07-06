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
    ll n, le, ri; cin >> n >> le >> ri;
    vl v(n); forr(x, v) cin >> x;

    vl pref(n+1); rep(i, 1, n+1) pref[i] = v[i-1]+pref[i-1];

    vl dp(n); dp[0] = v[0] >= le and v[0] <= ri;
    rep(i, 1, n){
        dp[i] = dp[i-1];

        int l = lower_bound(pref.begin(), pref.begin()+i, pref[i]-ri)-pref.begin();
        if(pref[i]-ri > ri) l--; 
        if(l == 0) continue;
        ll sum = pref[i]-pref[l];
        if(le <= sum and sum <= ri) dp[i] = max(dp[i], dp[i-l]+1);
    }

    forr(x, pref) cout << x << " ";
    cout << endl;
    forr(x, dp) cout << x << " ";
    cout << endl;
    cout << dp[n-1] << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
