#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){
	int n; cin >> n;
	vector<vector<int>> g(n); set<pair<int, int>> st;
	for(int i = 0; i < n; i++){ int x; cin >> x; --x; g[i].emplace_back(x), st.insert({i, x}); }

	for(int i = 0; i < n; i++){
		for(auto j: g[i]){
			for(auto k: g[j]) if(k != i and st.count({k, i})){ cout << "YES" << endl; exit(0); }
		}
	}

	cout << "NO" << endl;
	exit(0);
}
