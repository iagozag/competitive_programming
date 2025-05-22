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
	cout << "IMPOSSIBLE" << endl;
}

void solve(){
	int n, x; cin >> n >> x;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		int y; cin >> y; v.emplace_back(y, i);
	}
	sort(v.begin(), v.end());

	if(n < 3) return no();

	for(int i = 0; i < n-2; i++){
		int sum = x-v[i].first;
		if(sum <= 1) continue;
		int l = i+1, r = n-1;
		while(l < r){
			int tot = v[l].first+v[r].first;
			if(tot == sum){
				cout << v[i].second+1 << ' ' << v[l].second+1 << ' ' << v[r].second+1 << endl;
				return; 
			}
			if(tot < sum) l++;
			else r--;
		}
	}
	return no();
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
