#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;

#define int ll

const ld pi = acos(-1.0);

int32_t main(){
	int teta; int n; cin >> teta >> n;

	const ld tang = tan(teta*pi/180.0);

	vector<pair<int, int>> v(n);
	for(auto& [a, b]: v) cin >> a >> b;

	vector<pair<ld, ld>> w;
	for(int i = 0; i < n; i++){
		auto [x, h] = v[i];

		w.emplace_back(x, x+(ld)(h/tang));
	}

	sort(w.begin(), w.end());

	int m = w.size();
	for(int i = 0; i < m-1; i++){
		if(w[i].second >= w[i+1].first) 
			w[i+1] = {w[i].first, max(w[i].second, w[i+1].second)}, w[i] = {0, 0};
	}

	ld ans = 0;
	for(int i = 0; i < m; i++) ans += w[i].second-w[i].first;

	cout << fixed << setprecision(12) << ans << endl;

	exit(0);
}
