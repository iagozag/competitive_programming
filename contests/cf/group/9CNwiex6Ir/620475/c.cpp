#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	map<vector<int>, int> mp;
	vector<vector<int>> sets(n);
	for(int i = 0; i < n; i++){
		string s; cin >> s;

		for(int j = 0; j < m/2; j++) 
			sets[i].emplace_back((((int)(s[m-j-1]-'a')-(int)(s[j]-'a'))+26)%26);

		mp[sets[i]]++;
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		vector<int> need;
		for(auto x: sets[i]) need.emplace_back((26-x)%26);
		ans += mp[need];
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
