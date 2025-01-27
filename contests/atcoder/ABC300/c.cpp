#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<pair<int, int>> moves = {{-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

int n, m;
vector<string> v;

bool ok(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m;
}

void solve(){
	cin >> n >> m;
	 v = vector<string>(n); for(auto& x: v) cin >> x;

	vector<int> ans;
	for(int k = 1; k <= min(n, m); k++){
		int res = 0;
		
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(v[i][j] == '#'){
			int cnt4 = 0;
			for(auto [a, b]: moves){
				int ci = i, cj = j, cnt = 0;
				for(int l = 0; l <= k; l++) if(ok(ci, cj)) cnt += v[ci][cj] == '#', ci += a, cj += b;
				if(cnt == k+1) cnt4++;
			}
			if(cnt4 == 4) res++;
		}

		ans.emplace_back(res);
	}

	int sum = 0;
	for(int i = (int)ans.size()-1; i >= 0; i--) ans[i] -= sum, sum += ans[i];
	for(auto& x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
