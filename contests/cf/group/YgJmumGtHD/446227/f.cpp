#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define int long long

int32_t main(){ _
	int n, m; cin >> n >> m;
	int v[n][m], v2[m][n];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j], v2[j][i] = v[i][j];

	int ans = 0;
	for(int i = 0; i < n; i++){
		int l = 0, r = 1;
		while(r < m){
			while(r < m and abs(v[i][r]-v[i][r-1]) <= 1) r++;
			ans = max(ans, r-l);
			l++;
			if(l == r) r++;
		}
	}
	for(int i = 0; i < m; i++){
		int l = 0, r = 1;
		while(r < n){
			while(r < n and abs(v2[i][r]-v2[i][r-1]) <= 1) r++;
			ans = max(ans, r-l);
			l++;
			if(l == r) r++;
		}
	}

	cout << ans << endl;

	exit(0);

}
