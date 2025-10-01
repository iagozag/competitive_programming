#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

int32_t main(){ _
	int n, q; cin >> n >> q;
	vector<vector<int>> rows(n), cols(n);
	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b; --a, --b;
		rows[a].emplace_back(b), cols[b].emplace_back(a);
	}

	for(int i = 0; i < n; i++){
		rows[i].emplace_back(-1), rows[i].emplace_back(n);
		cols[i].emplace_back(-1), cols[i].emplace_back(n);
		sort(rows[i].begin(), rows[i].end()), sort(cols[i].begin(), cols[i].end());
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (int)rows[i].size()-1; j++){
			int val = rows[i][j+1]-rows[i][j]-1;
			if(val >= 1) ans += (val)*(val+1)/2-val;
		}
		for(int j = 0; j < (int)cols[i].size()-1; j++){
			int val = cols[i][j+1]-cols[i][j]-1;
			if(val-1 >= 1) ans += (val)*(val+1)/2-val;
		}
	}

	cout << ans+n*n-q << endl;
}
