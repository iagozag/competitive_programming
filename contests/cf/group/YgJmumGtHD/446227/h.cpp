#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define int long long

const int INF = 0x3f3f3f3f;

int32_t main(){ _
	int n; cin >> n;
	string s; cin >> s;

	vector<int> v(n+1); vector<int> mp(1<<26);
	int mask = 0, ans = 0; mp[0]++;
	for(int i = 1; i <= n; i++){
		mask ^= (1LL<<(s[i-1]-'a'));
		ans += mp[mask];
		for(int j = 0; j < 26; j++) if(j != 0 and j != 4 and j != 8 and j != 14 and j != 20 and j != 24)
			ans += mp[mask^(1LL<<j)];
		
		mp[mask]++;
	}

	cout << ans << endl;

	exit(0);

}
