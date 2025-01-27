#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){
	cout << -1 << endl;
}

void make(vector<int>& v, int i, int cnt){
	vector<int> tmp;

	bool can = 0; int num = 0, j = 0;
	while(j < (int)v.size() and !(v[j]&(1<<i))) tmp.emplace_back(v[j++]);

	int cnt2 = 0;
	for(; j < (int)v.size(); j++){
		if(cnt == cnt2) break;

		if(!can)
			while(j < (int)v.size() and !(v[j]&(1<<i))) tmp.emplace_back(v[j++]);

		num ^= v[j];
		if((1<<i)&v[j]){
			if(!can) can = 1;
			else tmp.emplace_back(num), can = 0, num = 0;

			cnt2++;
		}
	}

	while(j < (int)v.size()) tmp.emplace_back(v[j++]);

	v = tmp;
}

void solve(){
	int n, x; cin >> n >> x;
	vector<int> v(n); for(auto& y: v) cin >> y;

	int ans = -1;
	for(int i = 30; i >= 0; i--){
		int cnt = 0;
		for(int j = 0; j < (int)v.size(); j++) if(v[j]&(1<<i)) cnt++;

		if((1<<i) > x or !((1<<i)&x)){
			if(!cnt) continue;
			if(cnt&1){
				if(ans == -1) return no();
				cout << ans << endl;
				return;
			}

			make(v, i, cnt);
		} else if(cnt%2 == 0){
			vector<int> tmp = v;
			make(tmp, i, cnt);
			if(tmp.size()) ans = max(ans, (int)tmp.size());
		}
	}

	int y = 0;
	for(auto z: v) y |= z;

	if(y <= x) ans = max(ans, (int)v.size());

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
