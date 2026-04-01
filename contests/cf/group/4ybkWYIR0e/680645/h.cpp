#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e4+10, MOD = 1e9+7;

vector<vector<int>> pref(MAX, vector<int>(MAX));

void solve(){
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		pref[x][y]++;
	}

	for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++){
		pref[i][j] += (i ? pref[i-1][j] : 0)+(j ? pref[i][j-1] : 0)-(i and j ? pref[i-1][j-1] : 0);
	}
	
	auto get_rect = [&](int a, int b, int c, int d){
		return pref[c][d]-(a ? pref[a-1][d] : 0)-(b ? pref[c][b-1] : 0)+(a and b ? pref[a-1][b-1] : 0);
	};

	for(int i = 0; i < q; i++){
		int x, y, k; cin >> x >> y >> k;
		int l = 0, r = 1e4, ans = r;
		while(l <= r){
			int mid = l+(r-l)/2;

			if(get_rect(max(0, x-mid), max(0, y-mid), min(x+mid, MAX-1), min(y+mid, MAX-1)) >= k) ans = mid, r = mid-1;
			else l = mid+1;
		}

		cout << ans << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
