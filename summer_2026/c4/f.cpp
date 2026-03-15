#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
	string s; cin >> s; int n = s.size();
	map<char, int> mp;
	for(auto c: s) mp[c]++;
	int cnt = 0;
	for(auto [a, b]: mp) cnt += (b&1);
	if(cnt > 1){ cout << "NO SOLUTION" << endl; return; }

	string ans = string(n, ' '); int j = 0;
	for(auto [a, b]: mp) if(b%2 == 0){
		for(int i = 0; i < b/2; i++) ans[j] = ans[n-j-1] = a, j++;
	}

	for(auto [a, b]: mp) if(b%2){
		while(j < n and ans[j] == ' ') ans[j] = ans[n-j-1] = a, j++;
	}

	cout << ans << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;
	while(ttt--) solve();

	exit(0);
}

