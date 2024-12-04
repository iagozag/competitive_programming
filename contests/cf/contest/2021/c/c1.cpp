#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m, Q; cin >> n >> m >> Q;
	list<int> v; for(int i = 0; i < n; i++){ int a; cin >> a; v.push_back(a); }
	vector<int> q(m); vector<int> last(m, m); map<int, int> mp;
	for(int i = 0; i < m; i++){
		int a; cin >> a; q[i] = a;
		if(mp.count(a)) last[mp[a]] = min(n, i-mp[a]);
		mp[a] = i;
	}

	for(int i = 0; i < m; i++){
		int a = v.front(); v.pop_front();
		if(a != q[i]){ cout << "TIDAK" << endl; return; }

		auto it = next(v.begin(), (min((int)v.size()+1, last[i])-1));
		if(last[i] != m) v.insert(it, a);
	}
	cout << "YA" << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
