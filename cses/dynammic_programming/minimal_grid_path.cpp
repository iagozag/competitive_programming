#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<pair<int, int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void solve(){
	int n; cin >> n;
	vector<string> v(n);
	for(auto& x: v) cin >> x;

	if(n == 1){ cout << v[0][0] << endl; return; }

	vector<vector<int>> vis(n, vector<int>(n));

	vector<vector<int>> can(n, vector<int>(n)); queue<pair<int, int>> q; 
	q.push({0, 1}), q.push({1, 0}), can[0][0] = 1;
	for(int i = 1; i < 2*n-1; i++){
		vector<tuple<int, int, int>> candidates;
		int sz = q.size();
		for(int m = 0; m < sz; m++){
			auto [j, k] = q.front(); q.pop();

			for(int l = 0; l < 2; l++){
				auto [a, b] = moves[l];
				a += j, b += k;
				if(a >= 0 and b >= 0 and can[a][b]){ candidates.emplace_back(v[j][k], j, k); break; }
			}
		}

		sort(candidates.begin(), candidates.end()); char mi = get<0>(candidates[0]);
		for(auto [a, b, c]: candidates){
			if(a > mi) break;
			can[b][c] = 1;

			for(int l = 2; l < 4; l++){
				auto [x, y] = moves[l];
				x += b, y += c;
				if(x < n and y < n and !vis[x][y]) q.push({x, y}), vis[x][y] = 1;
			}
		}
	}

	int i = n-1, j = n-1; string ans = "";
	for(int k = 0; k < 2*n-1; k++){
		ans += v[i][j];
		for(int l = 0; l < 2; l++){
			auto [a, b] = moves[l];
			a += i, b += j;
			if(a >= 0 and b >= 0 and can[a][b]){ i = a, j = b; break; }
		}
	}

	reverse(ans.begin(), ans.end());

	cout << ans << endl;
}	

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
