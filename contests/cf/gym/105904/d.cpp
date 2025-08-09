#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
#define int ll

int32_t main(){ _
	int n, m, p, s; cin >> n >> m >> p >> s;
	vector<vector<int>> g(n, vector<int>(n));
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a][b] = g[b][a] = 1;
	}

	int ans = 0;
	for(int i = 0; i < (1<<n); i++){
		int cnt = 0;
		for(int j = 0; j < p; j++) if(i&(1<<j)) cnt++;
		if(cnt != 1) continue;

		cnt = 0;
		for(int j = p; j < p+s; j++) if(i&(1<<j)) cnt++;
		if(cnt != 1) continue;

		bool can = 1;
		for(int j = 0; j < n; j++) for(int k = j+1; k < n; k++)
			if((i&(1<<j)) and (i&(1<<k)) and g[j][k]) can = 0;

		if(can) ans++;
	}

	cout << ans << endl;

	exit(0);
};
