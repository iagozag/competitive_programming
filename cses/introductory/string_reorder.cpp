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
	string s; cin >> s; int n = s.size();
	vector<int> v(26); for(auto c: s) v[c-'A']++;
	vector<int> mi(26, n);
	for(int i = 0; i < 26; i++) if(v[i]) mi[i] = n-1-2*(v[i]-1);
	
	vector<char> ans(n, '-');

	for(int i = 0; i < 26; i++){
		int letter = i;
		int j = 0;
		while(j < n and ans[j] != '-') j++;
		for(; j < n and v[i]; j += 2, v[i]--) ans[j] = (char)(i+'A');

		if(j >= n and v[i]){ cout << -1 << endl; return; }
	}

	for(auto c: ans) cout << c << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
