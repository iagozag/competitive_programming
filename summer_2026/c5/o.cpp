#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int i = n-1, j = m-1, ans = 0;
	while(i >= 0 and j >= 0){
		if(abs(a[i]-b[j]) <= k) i--, j--, ans++;
		else if(a[i] > b[j]) i--;
		else j--;
	}

	cout << ans << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


