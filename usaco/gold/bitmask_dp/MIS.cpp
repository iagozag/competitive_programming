#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
int adj[40][40];

void calc(vector<int> v, int* dp, int sz){
	vector<bool> can;
	for(int i = 0; i < (int)sz; i++){
		for(int j = 0; j < n; j++){
			
		}
	}

	memset(dp, 0, sizeof(int)*sz);
	for(int i = 0; i < (int)sz; i++){
		for(int j = i; j; j = (j-1)&i){
			int ot = i^j;	
		}
	}
}

void solve(){
	cin >> n >> m;
	memset(adj, 0, sizeof adj);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		adj[a][b] = adj[b][a] = 1;
	}

	vector<int> v1, v2;
	for(int i = 0; i < n; i++){
		if(i < n/2) v1.emplace_back(i);
		else v2.emplace_back(i);
	}
	
	int sz1 = (int)(1<<v1.size()), sz2 = (int)(1<<v2.size()), dp1[sz1], dp2[sz2];
	calc(v1, dp1, sz1), calc(v2, dp2, sz2);

	int ans = 0;
	for(int i = 0; i < (int)sz1; i++){
		int can = sz2-1;
		for(int k = 0; k < (int)v1.size(); k++) if(i&(1<<k))
			for(int j = 0; j < (int)v2.size(); j++) if(adj[v1[k]][v2[j]] and can&(1<<j))
				can ^= (1<<j);

		ans = max(ans, dp1[i]+dp2[can]);
	}

	cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
