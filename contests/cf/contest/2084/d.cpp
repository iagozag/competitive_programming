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
	int n, m, k; cin >> n >> m >> k;
	
	vector<int> ans(n);
	int l = 1, r = n-1, mex = 0;
	while(l <= r){
		int mid = l+(r-l)/2;

		vector<int> v(n, -1);

		int x = 0;
		for(int i = 0; i < n; i++) if(v[i] == -1){
			for(int j = i; j < n; j += max(mid, k)) v[j] = x;

			x++;
		}

		vector<int> tmp = v;

		int ma = 0;
		for(int i = 0; i < n; i++) if(v[i] == mid-1) ma++;

		set<int> st; for(int i = 0; i <= x; i++) st.insert(i);

		int cnt = 0;
		for(int i = 0; i < n; i++) if(v[i] == 0 and cnt < m){
			for(int j = i; j < min(i+k, n); j++) v[j] = -1;
			i += k-1, cnt++;
		}

		for(int i = 0; i < n; i++) if(v[i] != -1){
			if(st.count(v[i])) st.erase(v[i]);
		}

		if(*st.begin() < mid or ma <= m) r = mid-1;
		else mex = mid, ans = tmp, l = mid+1;
	}

	// cout << mex << endl;

	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
