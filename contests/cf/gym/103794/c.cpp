#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define ff first 
#define ss second
#define sz(x) (int)x.size()
#define int ll

int32_t main() { _
    int n; cin >> n;
    vector<int> v(n); for(auto& x: v) cin >> x;
    int dp[n][2]; dp[0][0] = 0, dp[0][1] = v[0];
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + v[i];
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
    return 0;

}