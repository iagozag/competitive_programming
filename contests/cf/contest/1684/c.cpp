#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		cin >> v[i][j];
	}

	auto good = [&]() -> bool{
		for(int i = 0; i < n; i++) for(int j = 0; j < m-1; j++)
			if(v[i][j] > v[i][j+1]) return false;

		return true;
	};

	auto swapc = [&](int a, int b) -> void{
		for(int i = 0; i < n; i++) swap(v[i][a], v[i][b]);
	};

	vector<vector<int>> v2 = v;
	for(int i = 0; i < n; i++) sort(v2[i].begin(), v2[i].end());

	vector<int> s;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) if(v[i][j] != v2[i][j])
			s.emplace_back(j);
	
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	if(s.size() == 0) cout << 1 << ' ' << 1 << endl;
	else if(s.size() > 2) cout << -1 << endl;
	else{
		swapc(s[0], s[1]);
		if(good()) cout << s[0]+1 << ' ' << s[1]+1 << endl;
		else cout << -1 << endl;
	}
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
