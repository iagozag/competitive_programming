#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
#define int ll

const int m = 1000'000'007;

int32_t main(){ _
    int n; cin >> n;

    vector<vector<int>> dp(n+1,vector<int>(27,0));
    dp[1][1] = 1;

    for(int i=2;i<=n;i++) {
        for(int l=1;l<=min(26ll,i);l++) {
            dp[i][l] += dp[i-1][l]*l;
            dp[i][l]%=m;
            if(l>1) {
                dp[i][l] += dp[i-1][l-1];
                dp[i][l]%=m;
            } 
        }
    }

    int ans=0;
    for(int i=1;i<27;i++) ans+=dp[n][i];

    cout << ans%m << '\n';

}