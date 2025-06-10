#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){
	cout << -1 << endl;
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> v(n, vector<int>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j], v[i][j]--;
	if(k >= n*m) return no();

	if(k == n*m-1){
		vector<int> qnt(3);
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) qnt[v[i][j]]++;
		cout << n*m-max({qnt[0], qnt[1], qnt[2]}) << endl;
		return;
	}

	if(k < (n*m)/2 or (n != 1 and m != 1)) return no();

	if(m == 1){
		vector<vector<int>> nv(m, vector<int>(n));
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) nv[j][i] = v[i][j];
		v = nv;
		swap(n, m);
	}

	int last = 0, ch = v[0][0];
	for(int i = 1; i < m; i++){
		if(v[0][i] != ch){
			if(i-last > k) return no();
			last = i, ch = v[0][i];
		}
	}
	if(m-last > k) return no();

	vector<vector<int>> pref(3, vector<int>(m));
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < m; j++) pref[i][j] = (j ? pref[i][j-1] : 0) + (v[0][j] != i);
	}

	auto get_sum = [&](int c, int l, int r) -> int{
		if(l < 0 or l > r or r >= m) return 0;
		return pref[c][r]-(l ? pref[c][l-1] : 0);
	};

	int ans = INF;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < m; j++){
			if(j <= k and m-1-j <= k) ans = min(ans, (v[0][j] == i ? 2 : 1)+get_sum(i, 0, j-1)+get_sum(i, j+1, m-1));
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
