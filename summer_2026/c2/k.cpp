#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){
	int n, q; cin >> n >> q;
	vector<vector<int>> dp(n, vector<int>(20));
	for(int i = 0; i < n; i++) cin >> dp[i][0];

	for(int i = 1; i < 20; i++) for(int j = 0; j < n; j++){
		int idx = j+(1<<(i-1));
		dp[j][i] = min(dp[j][i-1], (idx < n ? dp[idx][i-1] : LINF));
	}

	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b; --a, --b;
		int sz = b-a+1, bit = __lg(sz);
		cout << min(dp[a][bit], dp[b-(1<<bit)+1][bit]) << endl;
	}
}
