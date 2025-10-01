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
	string s; cin >> s;
	int ans = INF;

	vector<int> pos;
	for(int i = 0; i < n; i++){
		if(s[i] == 'a') pos.emplace_back(i);
	}

	int sz = pos.size(), i = sz/2;
	int l = i-1, r = i+1, sum = 0;
	while(l >= 0) sum += pos[l+1]-pos[l]-1, pos[l] = pos[l+1]-1, l--;
	while(r < sz) sum += pos[r]-pos[r-1]-1, pos[r] = pos[r-1]+1, r++;

	ans = sum;

	pos.clear();
	for(int j = 0; j < n; j++){
		if(s[j] == 'b') pos.emplace_back(j);
	}

	sz = pos.size(), i = sz/2;
	l = i-1, r = i+1, sum = 0;
	while(l >= 0) sum += pos[l+1]-pos[l]-1, pos[l] = pos[l+1]-1, l--;
	while(r < sz) sum += pos[r]-pos[r-1]-1, pos[r] = pos[r-1]+1, r++;

	ans = min(ans, sum);

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
