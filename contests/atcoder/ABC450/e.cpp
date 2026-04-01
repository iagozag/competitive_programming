#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

string x, y; 
vector<vector<int>> pref[2];
vector<vector<int>> sums(3, vector<int>(26));
vector<int> sz = {0};

int f(int n, int k, int c){
	if(k == 1) return pref[0][n][c];
	if(k == 2) return pref[1][n][c];

	if(n == sz[k]) return sums[k][c];
	if(n > sz[k-1]) return sums[k-1][c] + f(n-sz[k-1], k-2, c);
	return f(n, k-1, c);
}

void solve(){
	cin >> x >> y; sz.emplace_back(x.size()), sz.emplace_back(y.size());

	pref[0] = vector<vector<int>>(sz[1]+1, vector<int>(26));
	pref[1] = vector<vector<int>>(sz[2]+1, vector<int>(26));
	for(int i = 1; i <= sz[1]; i++){
		for(int j = 0; j < 26; j++) pref[0][i][j] = pref[0][i-1][j];
		pref[0][i][x[i-1]-'a']++;
		sums[1][x[i-1]-'a']++;
	}
	for(int i = 1; i <= sz[2]; i++){
		for(int j = 0; j < 26; j++) pref[1][i][j] = pref[1][i-1][j];
		pref[1][i][y[i-1]-'a']++;
		sums[2][y[i-1]-'a']++;
	}

	int K = 2;
	while(sz[K] < 1e18){
		K++; sz.emplace_back(0);
		sz[K] = sz[K-1]+sz[K-2];

		sums.push_back(vector<int>(26));
		for(int i = 0; i < 26; i++) sums[K][i] = sums[K-1][i]+sums[K-2][i];
	}
	
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int l, r; char c; cin >> l >> r >> c;
		cout << f(r, K, c-'a') - f(l-1, K, c-'a') << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
