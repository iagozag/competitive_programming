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
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n+1)); for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> v[i][j];
	for(int i = 0; i < n; i++) for(int j = n-1; j >= 0; j--) v[i][j] += v[i][j+1];

	multiset<int> st;
	for(int i = 0; i < n; i++){
		int j = n;
		while(j >= 0 and v[i][j] == n-j) j--;
		st.insert(n-j);
	}
	int ans = 0;
	for(auto x: st) if(x > ans) ans++;
	
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
