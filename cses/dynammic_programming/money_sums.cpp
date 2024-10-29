#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> v(n); for(auto& x: v) cin >> x;
    vector<int> dp(1e5+1); dp[0] = 1;
    for(int i = 0; i < n; i++) for(int j = 1e5; j >= v[i]; j--) dp[j] |= dp[j-v[i]];
    vector<int> ans;
    for(int i = 1; i < 1e5+1; i++) if(dp[i]) ans.emplace_back(i);
    cout << ans.size() << endl;
    for(auto x: ans) cout << x << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
