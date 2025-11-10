#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll

const int LINF = 0x3f3f3f3f3f3f3fll;

int32_t main(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;

	vector<pair<int, int>> pref(n, {LINF, -1}), suf(n, {LINF, -1}); pair<int, int> cur = {LINF, -1};
	for(int i = 0; i < n; i++){
		if(v[i]) cur = {v[i], i};
		pref[i] = cur;
	}
	for(int i = n-1; i >= 0; i--){
		if(v[i]) cur = {v[i], i};
		suf[i] = cur;
	}

	int l = 0, r = n-1;
	for(int i = 1; i <= n; i++){
		if(v[l] == i){ l++; continue; }
		if(v[r] == i){ r--; continue; }

		if(v[l] and v[r]){ cout << '*' << endl; return 0; }
		if(v[l]) v[r--] = i;
		else if(v[r]) v[l++] = i;
		else{
			if(suf[l].first < pref[r].first or (suf[l].first == pref[r].first and abs(l-suf[l].second) < abs(r-pref[r].second)))
				v[l++] = i;
			else v[r--] = i;
		}
	}

	for(int i = 0; i < n; i++) cout << v[i] << ' ';
	cout << endl;

	exit(0);
}
