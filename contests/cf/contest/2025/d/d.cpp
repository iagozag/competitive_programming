#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5010, MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	vector<int> v(n); for(auto& x: v) cin >> x;

	vector<vector<int>> dp(m+1, vector<int>(m+1));
	vector<int> mp1(m+1), mp2(m+1); int cnt = m, tot2 = 0;
	for(int t = n-1; t >= 0; t--){
		if(!v[t]){
			cnt--; int sum1 = 0, sum2 = tot2-mp2[cnt+1];
			for(int i = 0; i <= cnt; i++){
				dp[i][cnt-i] = max(dp[i+1][cnt-i]+sum1+mp1[i+1]+sum2,
								   dp[i][cnt-i+1]+sum1+sum2+mp2[cnt-i+1]);
				sum1 += mp1[i+1], sum2 -= mp2[cnt-i], mp1[i+1] = 0, mp2[cnt-i+1] = 0;
			}
			tot2 = 0, mp2[1] = 0;
		} 
		else if(v[t] > 0 and v[t] <= cnt) mp1[v[t]]++;
		else if(v[t] < 0 and -v[t] <= cnt) mp2[-v[t]]++, tot2++;	
	}

	cout << dp[0][0] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
