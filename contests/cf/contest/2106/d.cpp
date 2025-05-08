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
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	vector<int> left(n), right(n); int j = 0;
	for(int i = 0; i < n; i++){
		if(i) left[i] = left[i-1];
		if(j < m and a[i] >= b[j]) left[i]++, j++;
	}

	j = m-1;
	for(int i = n-1; i >= 0; i--){
		if(i < n-1) right[i] = right[i+1];
		if(j >= 0 and a[i] >= b[j]) right[i]++, j--;
	}

	if(left.back() == m or right[0] == m){ cout << 0 << endl; return; }

	set<pair<int, int>> st;
	for(int i = -1; i < n; i++) st.insert({(i >= 0 ? left[i] : 0), (i < n-1 ? right[i+1] : 0)});

	int ans = LINF;
	for(int i = 0; i < m; i++){
		if(st.count({i, m-i-1})) ans = min(ans, b[i]);
	}

	cout << (ans == LINF ? -1 : ans) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
