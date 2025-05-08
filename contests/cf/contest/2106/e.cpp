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
	vector<int> v(n), pos(n);
	for(int i = 0; i < n; i++) cin >> v[i], --v[i], pos[v[i]] = i;

	for(int Q = 0; Q < q; Q++){
		int l, r, x; cin >> l >> r >> x; --l, --r, --x;

		if(pos[x] < l or pos[x] > r){ cout << -1 << ' '; continue; }

		int ans = 0;
		while(l <= r){
			int m = (l+r)/2;

			if(v[m] > x and pos[x] > m) ans++;
			else if(v[m] < x and pos[x] < m) ans++;

			if(m < pos[x]) l = m+1;
			else if(m > pos[x]) r = m-1;
			else break;
		}

		cout << ans << ' ';
	}

	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
