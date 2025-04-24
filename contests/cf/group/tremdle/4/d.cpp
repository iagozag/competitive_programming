#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e6+10, MOD = 1e9+7;

void solve(){
	string s; cin >> s; int n = s.size();
	reverse(s.begin(), s.end());

	vector<int> v(MAX);

	int l = 0, r = 0;
	while(r < n){
		while(l < n and s[l] == '0') l++;
		r = l;

		while(r < n){
			if(s[r] == '0' and (r-l <= 1 or s[r+1] != '1')) break;
			if(s[r] == '0') v[r]--;
			r++;
		}
		
		if(r-l > 1) v[r]++, v[l]--;
		else v[r-1]++;

		l = r;
	}

	for(int i = 0; i < MAX; i++){
		if(v[i] > 0){
			v[i+1] += v[i]/2;
			v[i] %= 2;
		} else if(v[i] < 0){
			v[i+1] += v[i]/2;
			if(abs(v[i])&1) v[i] = -1;
			else v[i] = 0;
		}
	}

	vector<pair<int, int>> ans;
	for(int i = 0; i < 2e6+10; i++) if(v[i] != 0){
		ans.emplace_back(v[i] < 0, i);
	}

	cout << ans.size() << endl;
	for(auto [a, b]: ans){
		if(!a) cout << '+';
		else cout << '-';
		cout << "2^" << b << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
