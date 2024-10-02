#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void sum(ll& a, ll b){
    a += b, a %= MOD;
}

ll sumr(vector<ll>& pref, int l, int r){
    return ((pref[r]-(l ? pref[l-1] : 0))%MOD+MOD)%MOD;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    ll dp[n][n]; vector<ll> pref(n); fill(&dp[0][0], &dp[0][0]+n*n, 0);
    for(int i = 0; i < n; i++) dp[0][i] = 1, pref[i] = (i ? pref[i-1]+1 : 0);
    for(int i = 1; i < n; i++){
        vector<ll> npref(n);
        for(int j = 0; j < n; j++){
            if(s[i-1] == '>') sum(dp[i][j], (j < n-1 ? sumr(pref, j+1, n-1) : 0));
            else sum(dp[i][j], (j ? sumr(pref, 0, j-1) : 0));

            npref[j] = (j ? npref[j-1] : 0);
            sum(npref[j], dp[i][j]); 
        }
        swap(pref, npref);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) sum(ans, dp[n-1][i]);
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
