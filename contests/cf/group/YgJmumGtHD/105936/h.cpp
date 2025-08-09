#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){ cout << -1 << endl; }

void solve(){
	int n; cin >> n;
	vector<vector<int>> dt(n+1);
	vector<int> v(1<<n);
	for(int i = 0; i < (1<<n); i++) cin >> v[i], dt[v[i]].emplace_back(i);
	
	if(v[0] != 0) return no();

	vector<int> pos(1<<n, -1); pos[0] = 0;

	for(int j = n; j >= 1; j--){
		for(auto& x: pos) if(x != -1) x *= 2;

		int k = 0;
		vector<int> npos = pos;
		for(auto x: dt[j]){
			while(k < x and pos[k] == -1) k++;
			if(k == x) return no();
			npos[x] = pos[k]+1, k++;
		}
		swap(pos, npos);
	}

	vector<int> ans(1<<n);
	for(int i = 0; i < (1<<n); i++) ans[pos[i]] = i+1;
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
