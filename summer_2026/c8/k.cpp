#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	string s; cin >> s; int n = s.size();
	int sum = 0;
	for(auto x: s) sum += (int)(x-'0'), sum %= 3;
	vector<int> ans;

	int num = s.back()-'0';
	if(num%2 == 0) ans.emplace_back(2);
	if(sum == 0) ans.emplace_back(3);

	string last = ""; 
	if(n >= 2) last += s[n-2]; 
	last += s[n-1];
	if((int)stoll(last) % 4 == 0) ans.emplace_back(4);

	if(num == 0 or num == 5) ans.emplace_back(5);

	if(num%2 == 0 and sum == 0) ans.emplace_back(6);

	if(ans.empty()){ cout << -1 << endl; return; }

	for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i == (int)ans.size()-1];
}

int32_t main(){ _
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}
