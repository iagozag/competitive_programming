#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define int ll

typedef long long ll;

int32_t main(){ _
	int n; cin >> n;
	vector<pair<int, int>> v(n); for(auto& [a, b]: v) cin >> a >> b;
	vector<pair<int, int>> ans;
	set<int> vis;
	int t = 0;
	for(auto [a, b]: v){
		ans.emplace_back(a+b*t, t);
		t++;
	}

	cout << ans.size() << endl;
	for(auto [a, b]: ans) cout << a << ' ' << b << endl;
	
	exit(0);
}
