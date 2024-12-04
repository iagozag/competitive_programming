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
	int n; cin >> n;
	vector<vector<int>> v(n);
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(auto c: s) v[i].emplace_back(c-'0');
	}

	sort(v.begin(), v.end(), [&](vector<int> a, vector<int> b){
		return a.size() < b.size();
	});

	ll ans = 0; int mp[6][46]; memset(mp, 0, sizeof mp); 
	for(int i = 0; i < n; i++){
		int sum = 0, tot = 0, m = v[i].size();

		for(int j = 0; j < m; j++) tot += v[i][j];
		mp[m][tot]++;

		for(int t = 0; t <= 10; t += 2) if(t >= m and t <= 2*m){
			int need = t-m;

			// left
			sum = 0;
			for(int j = 0; j < t/2; j++) sum += v[i][j];
			if(sum-(tot-sum) >= 0) ans += mp[need][sum-(tot-sum)];

			// right
			sum = 0;
			for(int j = 0; j < t/2; j++) sum += v[i][m-j-1];
			if(sum-(tot-sum) >= 0) ans += mp[need][sum-(tot-sum)];
		}
	}

	cout << ans-n << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
