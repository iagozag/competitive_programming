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
	set<char> st; string s; cin >> s;
	for(auto& x: s) st.insert(x);
	if(st.size() == 1){ cout << -1 << endl; return; }

	int sum = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'o') sum++;
		else ans = max(ans, sum), sum = 0;
	}

	sum = 0;
	for(int i = n-1; i >= 0 ; i--){
		if(s[i] == 'o') sum++;
		else ans = max(ans, sum), sum = 0;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
