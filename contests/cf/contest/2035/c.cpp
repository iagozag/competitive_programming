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
	int n, k = 0; cin >> n;
	vector<int> ans(n); set<int> st;
	for(int i = 1; i <= n; i++) st.insert(i);
	if(n&1){
		ans[n-1] = n, ans[n-2] = n-1, ans[n-3] = 1, ans[n-4] = 3;

		for(int i = n-4; i < n; i++) st.erase(ans[i]);
		for(int i = 0; i < n-4; i++) ans[i] = *st.begin(), st.erase(*st.begin());
	} else{
		int num = 0;
		for(int i = 0; i < 32 and (1<<i) < n; i++) if(!((n>>i)&1)) num += 1<<i;

		if(num == 1) num = 3;
		ans[n-1] = n, ans[n-2] = num, ans[n-3] = num-1, ans[n-4] = 1;

		for(int i = n-4; i < n; i++) st.erase(ans[i]);
		for(int i = 0; i < n-4; i++) ans[i] = *st.begin(), st.erase(*st.begin());
	}

	for(int i = 0; i < n; i++){
		if(i&1) k |= ans[i];
		else k &= ans[i];
	}

	cout << k << endl;
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
