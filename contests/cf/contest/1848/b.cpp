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
	int n, k; cin >> n >> k;
	vector<vector<int>> pos(k);
	for(int i = 0; i < n; i++){
		int a; cin >> a; pos[a-1].emplace_back(i);
	}

	for(int i = 0; i < k; i++) pos[i].emplace_back(n);

	int mi = LINF;
	for(int i = 0; i < k; i++){
		vector<int> dist;
		for(int j = 0; j < (int)pos[i].size(); j++){
			if(j == 0) dist.emplace_back(pos[i][j]);
			else dist.emplace_back(pos[i][j]-pos[i][j-1]-1);
		}
		sort(dist.begin(), dist.end(), greater<int>());
		mi = min(mi, max(dist[0]/2, ((int)dist.size() > 1 ? dist[1] : 0)));
	}

	cout << mi << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
