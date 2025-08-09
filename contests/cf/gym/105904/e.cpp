#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
#define int ll

int32_t main(){ _
	int n, m; cin >> n >> m;
	vector<pair<int, int>> v(n); for(auto& [a, b]: v) cin >> a >> b;
	sort(v.begin(), v.end());

	int l = 0, r = 0, ma = 0, sum = 0, ans = 0;
	vector<int> pref(n);
	while(l < n){
		while(r < n and v[r].first-v[l].first <= m){
			sum += v[r].second, r++;
			ans = max(ans, sum+ma);
			pref[r-1] = max(pref[r-1], sum);
		}
		ans = max(ans, sum+ma);
		pref[r-1] = max(pref[r-1], sum);
		
		ma = max(ma, pref[l]), sum -= v[l].second, l++;
	}

	cout << ans << endl;

	exit(0);
};
