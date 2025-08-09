#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
#define int ll

int32_t main(){ _
	int n; cin >> n;
	vector<vector<int>> g(n);
	for(int i = 0; i < n; i++){ int x; cin >> x; --x; g[i].emplace_back(x), g[x].emplace_back(i); }

	int ans = 0;

	vector<int> vis(n);
	auto dfs = [&](auto &&self, int v) -> bool {

	};

	for(int i = 0; i < n; i++){

	}

    exit(0);
}
