#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void yes(){ cout << "Long lost brothers D:" << endl; }
void no(){ cout << "Not brothers :(" << endl; }

int OFF = 1020;

void solve(){
	string s, t; cin >> s >> t; int n = s.size();

	vector<int> dp(2*OFF+100), prev(2*OFF+100);
	for(int i = 0; i < n; i++){
		dp = vector<int>(2*OFF+100);
		for(int j = -1010; j <= 1010; j++){
			int k = i+j;
			if(k < 0 or k >= n) continue;

			if(s[i] == t[k]) dp[j+OFF] = prev[j+OFF]+1;
			else dp[j+OFF] = max(dp[j+OFF-1], prev[j+OFF+1]);
		}

		swap(dp, prev);
	}

	int ans = *max_element(prev.begin(), prev.end());

	if(100*ans >= 99*n) yes();
	else no();
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
