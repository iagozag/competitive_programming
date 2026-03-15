#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int MAX = 2e5+10, LINF = 0x3f3f3f3f3f3f3f3fll;

int n;

void no(){ cout << "black wins" << endl; }
void yes(){ cout << "white wins" << endl; }

void solve(){
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].first;
	for(int i = 0; i < n; i++) cin >> v[i].second;

	int ans = 0;
	for(int i = 0; i < n; i++) ans ^= v[i].second-v[i].first-1;

	return (ans == 0 ? no() : yes());
}

int32_t main(){
	int ttt = 1; cin >> ttt;
	for(int t = 1; t <= ttt; t++) cout << "Case " << t << ": ", solve();

	exit(0);
}

