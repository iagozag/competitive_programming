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
	vector<int> qnt(n);
	for(int i = 0; i < n; i++) cin >> qnt[i];

	vector<vector<string>> ans(n);
	for(int i = 0; i < m; i++){	
		string stud; cin >> stud;	
		int k; cin >> k;
		vector<int> mat(k);
		bool can = true;
		for(int j = 0; j < k; j++){
			cin >> mat[j]; mat[j]--;
			if(qnt[mat[j]] == 0) can = false;
		}
		if(can){
			for(int j = 0; j < k; j++) ans[mat[j]].emplace_back(stud), qnt[mat[j]]--;
		}
	}

	for(int i = 0; i < n; i++){
		cout << ans[i].size() << ' ';
		for(auto x: ans[i]) cout << x << ' ';
		cout << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

