#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<int> a;

void solve(){
	cin >> n;
	for(auto& x: a) cin >> x;

	vector<int> last(501, -1); vector<vector<int>> pos(n, vector<int>(501, -1));
	for(int i = 0; i < n; i++){
		last[a[i]] = i;
		for(int j = 0; j < a[i]; j++) if(last[j] != -1) pos[last[j]][a[i]] = i;
	}
	
	vector<vector<bool>> dp(n, vector<bool>(501)); dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = a[i]+1; j <= 500; j++) if(dp[i][j]){
			
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
