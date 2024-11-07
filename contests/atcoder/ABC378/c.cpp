#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> v(n); map<int, int> mp;
	for(auto& x: v) cin >> x;

	for(int i = 0; i < n; i++){
		if(!mp.count(v[i])) cout << -1 << " ";
		else cout << mp[v[i]]+1 << " ";
		mp[v[i]] = i;
	}
	cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
