#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<vector<int>> ans;

void f(vector<int> has){
	int h = has.size();
	if(h == n){ ans.emplace_back(has); return; }
	
	int a = has.back();
	for(int i = a+10; i <= m-(n-h-1)*10; i++){
		vector<int> tmp = has; tmp.emplace_back(i);
		f(tmp);
	}
}

void solve(){
	cin >> n >> m;

	for(int i = 1; i <= m-(n-1)*10; i++){
		f({i});
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto x: ans){ for(auto y: x) cout << y << " "; cout << endl; }
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
