#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	string s; cin >> s; int n = s.size();
	vector<pair<ll, ll>> last(26, {0, 0});
	ll ans = 0;
	for(int i = 0; i < n; i++){
		int c = (s[i]-'A');

		ans += max(0LL, last[c].first);
			
		for(int j = 0; j < 26; j++) last[j].first += last[j].second;

		last[c].second++;
	}
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
