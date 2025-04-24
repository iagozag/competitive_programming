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
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].first;
	for(int i = 0; i < n; i++) cin >> v[i].second;

	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b){
		if(a.second != b.second) return a.second < b.second;
		return a.first < b.first;
	});

	int damage = 0, i = 0;
	while(k > 0 and i < n){
		damage += k;
		while(i < n and damage >= v[i].first) i++;
		if(i == n) break;
		k -= v[i].second;
	}

	if(i == n) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
