#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

int32_t main(){ _
	int n, m, t; cin >> n >> m >> t;
	int v[n][m]; for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j];

	auto sum = [&](int* a, int* b) -> void {
		for(int i = 0; i < t; i++) a[i] += b[i];
	};
	auto sub = [&](int* a, int* b) -> void {
		for(int i = 0; i < t; i++) a[i] -= b[i];
	};

	int pref[n][m][t]; memset(pref, 0, sizeof pref);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		if(i) sum(pref[i][j], pref[i-1][j]);
		if(j) sum(pref[i][j], pref[i][j-1]);
		if(i and j) sub(pref[i][j], pref[i-1][j-1]);

		int tmp[t];
		for(int k = 0; k < t; k++) tmp[k] = ((v[i][j]>>k)&1);
		sum(pref[i][j], tmp);
	}

	int l = 1, r = n, best = 0; pair<int, int> square;
	while(l <= r){
		int mid = l+(r-l)/2;
		
		bool can = 1;
		for(int i = 0; i <= n-mid; i++){
			for(int j = 0; j <= m-mid; j++){
				int ans[t]; memset(ans, 0, sizeof ans);

				sum(ans, pref[i+mid-1][j+mid-1]);
				if(i) sub(ans, pref[i-1][j+mid-1]);
				if(j) sub(ans, pref[i+mid-1][j-1]);
				if(i and j) sum(ans, pref[i-1][j-1]);

				can = 1;
				for(int k = 0; k < t; k++) if(!ans[k]) can = 0;
				if(can){ best = mid, square = {i, j}; break; }
			}
			if(can) break;
		}

		if(can) r = mid-1;
		else l = mid+1;
	}

	if(best == 0) cout << -1 << endl;
	else cout << best*best << endl << square.first << ' ' << square.second << endl;

	exit(0);
}
