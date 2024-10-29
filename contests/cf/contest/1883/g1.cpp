#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	vector<int> a(n), b(n); a[0] = 1;
	for(int i = 1; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	sort(a.begin(), a.end()), sort(b.begin(), b.end());

	int l = 0, r = n, ans = n;
	while(l <= r){
		int mid = (l+r)>>1;

		vector<int> na, nb;
		for(int i = 0; i < n-mid; i++) na.emplace_back(a[i]);
		for(int i = mid; i < n; i++) nb.emplace_back(b[i]);

		bool good = 1;
		for(int i = 0; i < (int)na.size(); i++) if(na[i] >= nb[i]) good = 0;

		if(good) ans = mid, r = mid-1;
		else l = mid+1;
	}
	cout << ans << endl;


}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
