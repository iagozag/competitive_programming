#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll

int32_t main(){
	int k; string st; vector<int> s; cin >> k >> st;
	int n = st.size();
	for(int i = 0; i < n; i++){ s.emplace_back(st[i]-'0'); }

	if(k == 2){
		int sum1 = 0, sum2 = 0, cur = 0;
		for(int i = 0; i < n; i++) sum1 += abs(cur-s[i]), cur = !cur;

		cur = 1;
		for(int i = 0; i < n; i++) sum2 += abs(cur-s[i]), cur = !cur;

		cout << min(sum1, sum2) << ' ';

		if(sum1 <= sum2) cur = 0;
		else cur = 1;

		for(int i = 0; i < n; i++) cout << cur, cur = !cur;
		cout << endl;
		return 0;
	}
	
	int cur = 1, ans = 0;
	for(int i = 1; i < n; i++){
		if(s[i] == s[i-1]) cur++;
		else cur = 1;

		if(cur == k){
			ans++;
			if(i == n-1 or s[i] == s[i+1]) s[i] = !s[i];
			else s[i-1] = !s[i-1];
			cur = 1;
		}
	}

	cout << ans << ' ';
	for(auto x: s) cout << x;
	cout << endl;

	exit(0);
}
