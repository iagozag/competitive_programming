#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void yes(){
	cout << "YES" << endl;
}

void solve(){
	int n; cin >> n;
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		int x; cin >> x; mp[x]++;
	}

	int last = -1, cnt = 0;
	for(auto [a, b]: mp){
		if(b > 1){
			if(b >= 4) return yes();
			if(a-last-1 == cnt) return yes();

			last = a, cnt = 0;
		} else cnt++;
	}

	cout << "NO" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
