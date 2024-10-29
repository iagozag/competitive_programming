#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

ll fexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = ans*a%MOD;
        a = a*a%MOD, b >>= 1;
    }
    return ans;
}

void solve(){
    int n; cin >> n; int sum = n*(n+1)/2;
    if(sum&1){ cout << 0 << endl; return; }
    sum >>= 1;
    vector<ll> dp(sum+1); dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = sum; j >= i; j--) dp[j] += dp[j-i], dp[j] %= MOD;
    }
    cout << dp[sum]*fexp(2, MOD-2)%MOD << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
