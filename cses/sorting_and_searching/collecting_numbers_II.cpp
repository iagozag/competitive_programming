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
	int n, q; cin >> n >> q;
	vector<int> v(n), nums(n);
	for(int i = 0; i < n; i++){ int x; cin >> x; nums[i] = x-1, v[x-1] = i; }

	int ans = 0;
	for(int i = 1; i < n; i++) if(v[i] < v[i-1]) ans++;

	for(int Q = 0; Q < q; Q++){
		int a, b; cin >> a >> b; --a, --b; if(a > b) swap(a, b);
		if(a and v[a] < v[a-1]) ans--;
		if(b > a+1 and v[a+1] < v[a]) ans--;

		if(v[b] < v[b-1]) ans--;
		if(b < n-1 and v[b+1] < v[b]) ans--;

		int x = nums[a], y = nums[b];
		swap(nums[a], nums[b]);
		swap(v[x], v[y]);

		if(a and v[a] < v[a-1]) ans++;
		if(b > a+1 and v[a+1] < v[a]) ans++;

		if(v[b] < v[b-1]) ans++;
		if(b < n-1 and v[b+1] < v[b]) ans++;
		
		cout << ans+1 << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
