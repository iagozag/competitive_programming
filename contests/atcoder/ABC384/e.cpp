#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
bool val(int a, int b){
	return (a >= 0 and a < n and b >= 0 and b < m);
}

void solve(){
	int x; cin >> n >> m >> x;
	int p, q; cin >> p >> q; --p, --q;
	int mat[n][m]; for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> mat[i][j];
	bool vis[n][m]; memset(vis, 0, sizeof vis); vis[p][q] = 1;

	int sum = mat[p][q]; priority_queue<pair<int, pair<int, int>>> pq;
	for(auto [a, b]: moves){
		a += p, b += q;
		if(val(a, b)) vis[a][b] = 1, pq.push({-mat[a][b], {a, b}});
	}

	while(!pq.empty()){
		auto [a, b] = pq.top(); pq.pop(); a *= -1LL;
		auto [i, j] = b;
		if((sum%x == 0 and sum/x <= a) or (sum%x != 0 and sum/x < a)) continue;

		sum += a;
		for(auto [y, z]: moves){
			y += i, z += j;
			if(val(y, z) and !vis[y][z]) pq.push({-mat[y][z], {y, z}}), vis[y][z] = 1;
		}
	}

	cout << sum << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
