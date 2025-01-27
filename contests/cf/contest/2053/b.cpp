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
	vector<pair<int, int>> v(n);
	vector<int> pref(2*n+1); map<pair<int, int>, int> mp;
	for(auto& [a, b]: v){
		cin >> a >> b; mp[{a, b}]++;
		if(a == b) pref[a] = 1;
	}
	for(int i = 1; i < 2*n+1; i++) pref[i] += pref[i-1];

	for(int i = 0; i < n; i++){
		auto [a, b] = v[i];
		if(a == b) cout << (mp[{a, b}] == 1 ? 1 : 0);
		else if(pref[b]-pref[a-1] == (b-a+1)) cout << 0;
		else cout << 1;
	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
