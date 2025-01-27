#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<int> v;
unordered_set<int> ans;

void f(int i, int x){
	if(i == n){
		ans.insert(x);
		return;
	}

	for(int j = i+1; j < n; j++) if(v[j]){
		int tmp = v[i];
		v[i] = 0, x ^= v[j], v[j] += tmp, x ^= tmp, x ^= v[j];
		f(i+1, x);
		x ^= v[j], x ^= tmp, v[j] -= tmp, x ^= v[j], v[i] = tmp;
	}
	f(i+1, x);
}

void solve(){
	cin >> n; v = vector<int>(n); 
	int y = 0;
	for(auto& x: v) cin >> x, y ^= x;

	f(0, y);

	cout << ans.size() << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
