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
	vector<int> v;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		int ub = upper_bound(v.begin(), v.end(), x)-v.begin();
		if(ub == (int)v.size()) v.emplace_back(x);
		else v[ub] = x;
	}

	cout << (int)v.size() << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
