#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m, k, ans;
vector<vector<map<int, int>>> v;
vector<vector<int>> mat;


void f1(int i, int j, int x){
	x ^= mat[i][j];
	if(i+j == (n+m-2)/2){
		v[i][j][x]++;
		return;
	}

	if(i+1 < n) f1(i+1, j, x);
	if(j+1 < m) f1(i, j+1, x);
}

void f2(int i, int j, int x){
	x ^= mat[i][j];
	if(i+j == (n+m-2)/2){
		x ^= mat[i][j];
		ans += v[i][j][x^k];
		return;
	}

	if(i-1 >= 0) f2(i-1, j, x);
	if(j-1 >= 0) f2(i, j-1, x);
}

void solve(){
	cin >> n >> m >> k;
	mat = vector<vector<int>>(n, vector<int>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> mat[i][j];

	v = vector<vector<map<int, int>>>(vector<vector<map<int, int>>>(n, vector<map<int, int>>(m)));

	ans = 0;
	f1(0, 0, 0);
	f2(n-1, m-1, 0);

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
