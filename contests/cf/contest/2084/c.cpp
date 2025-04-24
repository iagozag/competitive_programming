#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){
	cout << -1 << endl;
}

int n; 
vector<int> a, b;
vector<pair<int, int>> op;
map<pair<int, int>, int> mp;

void change(int i, int j){
	op.push_back({i, j});
	swap(mp[{a[i], b[i]}], mp[{a[j], b[j]}]);
	swap(a[i], a[j]), swap(b[i], b[j]);
}

void solve(){
	op.clear(), mp.clear();

	cin >> n;
	a = b = vector<int>(n);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	int extra = 0, idx = -1;
	for(int i = 0; i < n; i++){
		if(a[i] == b[i]) extra++, idx = i;
		mp[{a[i], b[i]}] = i;
	}

	if(extra > 1 or (extra == 1 and n%2 == 0) or (n&1 and extra == 0)) return no();

	if(extra and idx != n/2) change(idx, n/2);

	for(int i = 0; i < n/2; i++){
		if(!mp.count({b[i], a[i]})) return no();

		if(mp[{b[i], a[i]}] != n-i-1) change(mp[{b[i], a[i]}], n-i-1);
	}

	cout << (int)op.size() << endl;
	for(auto [x, y]: op) cout << x+1 << ' ' << y+1 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
