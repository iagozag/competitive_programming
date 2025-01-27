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
	int n, k; cin >> n >> k;
	string a, b; cin >> a >> b;
	set<char> st; for(auto x: a) st.insert(x);
	
	vector<string> perm;
	for(int i = 0; i < (1<<(int)st.size()); i++) if(__builtin_popcount(i) == min(k, (int)st.size())){
		int l = 0; perm.emplace_back("");
		for(auto x: st){ if(i&(1<<l)) perm.back() += x; l++; }
	}

	int ans = 0;
	for(int i = 0; i < (int)perm.size(); i++){
		int tot = 0, l = -1, r = -1;
		for(int j = 0; j < n; j++){
			if(a[j] == b[j] or perm[i].find(a[j]) != string::npos){
				if(l == -1) l = j, r = j;
				else r++;
			} else{
				if(l != -1 and r != -1) tot += (r-l+1)*(r-l+2)/2;
				l = -1, r = -1;
			}
		}
		if(l != -1 and r != -1) tot += (r-l+1)*(r-l+2)/2;
		ans = max(ans, tot);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
