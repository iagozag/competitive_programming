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
	int n; cin >> n;
	vector<pair<int, int>> ans = {{1, 3}};
	for(int i = 2; i <= n; i++){
		vector<pair<int, int>> prev = ans;
		ans.clear();
		for(auto [a, b]: prev){
			pair<int, int> p;
			if(a == 1) p.first = 1;
			else if(a == 2) p.first = 3;
			else if(a == 3) p.first = 2;
			if(b == 1) p.second = 1;
			else if(b == 2) p.second = 3;
			else if(b == 3) p.second = 2;

			ans.push_back(p);
		}
		ans.push_back({1, 3});

		for(auto [a, b]: prev){
			pair<int, int> p;
			if(a == 1) p.first = 2;
			else if(a == 2) p.first = 1;
			else if(a == 3) p.first = 3;
			if(b == 1) p.second = 2;
			else if(b == 2) p.second = 1;
			else if(b == 3) p.second = 3;

			ans.push_back(p);
		}
	}

	cout << ans.size() << endl;
	for(auto [a, b]: ans) cout << a << ' ' << b << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
