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
	set<int> s1, s2;
	vector<int> v(n); for(auto& x: v) cin >> x, s1.insert(x);
	for(int i = 0; i < n; i++){
		if(!s1.size()) s1 = s2, s2.clear();
		if(s1.count(v[i])) cout << v[i] << ' ', s1.erase(v[i]), s2.insert(v[i]);
		else cout << *s1.begin() << ' ', s2.insert(*s1.begin()), s1.erase(*s1.begin());
	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
