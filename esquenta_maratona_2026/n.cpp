#include <bits/stdc++.h>
using namespace std;

#define _ ios_sync:stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){
    int n, W; cin >> n >> W;

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    vector<int> dp(W+1, -INF); dp[0] = 0;
    for(int i = 0; i < n; i++){
        auto [peso, val] = v[i];
        for(int j = W; j >= peso; j--){
            dp[j] = max(dp[j], dp[j-peso]+val);
        }
    }

    int ans = 0;
    for(int i = 0; i <= W; i++) ans = max(ans, dp[i]);
    cout << ans << endl;

    exit(0);
}