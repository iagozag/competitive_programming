#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
	int n; cin >> n;
	vector<pair<int, int>> movies(n); for(auto& [a, b]: movies) cin >> a >> b;
	sort(movies.begin(), movies.end(), [&](pair<int, int> a, pair<int, int> b){
		if(a.first != b.first) return a.first > b.first;
		return a.second < b.second;
	});

	int last = movies[0].first, ans = 1;
	for(int i = 1; i < n; i++){
		if(last >= movies[i].second) ans++, last = movies[i].first;
	}

	cout << ans << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;
	while(ttt--) solve();

	exit(0);
}

