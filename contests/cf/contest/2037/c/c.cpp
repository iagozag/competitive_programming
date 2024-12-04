#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

bool is_p(int n){
	for(int i = 2; i < sqrt(n)+1; i++) if(n%i == 0) return false;
	return true;
}

void solve(){
	int n; cin >> n;
	if(n <= 4){ cout << -1 << endl; return; }

	set<int> st; for(int i = 1; i <= n; i++) st.insert(i);
	vector<int> ans(n); int i = 0;
	for(int j = 1; j <= n; j += 2) ans[i++] = j, st.erase(j);
	for(auto x: st) if(!is_p(ans[i-1]+x)){ ans[i++] = x; break; }
	st.erase(ans[i-1]);
	for(auto x: st) ans[i++] = x;	
	for(i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
