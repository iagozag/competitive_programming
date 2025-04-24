#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

set<int> st;

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v){
		cin >> x;
		if(x <= 1e5) st.erase(x);
	}

	for(int i = 0; i < 2*n+2; i++){
		if(i%2 == 0) cout << *st.begin() << endl, v.emplace_back(*st.begin()), st.erase(*st.begin());
		else{
			int x; cin >> x;
			if(x == -1) break;
			if(x <= MAX) st.insert(x);
		}
	}

	for(auto x: v) st.insert(x);
}

int32_t main(){
    int ttt = 1; cin >> ttt;

	for(int i = 0; i < MAX; i++) st.insert(i);

    while(ttt--) solve();

    exit(0);
}
