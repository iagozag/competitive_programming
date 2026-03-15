#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int32_t main(){
    int n; cin >> n; const int B = sqrt(n);
    vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> mp(1e6+1); int ans = 0;
    auto add = [&](int i){
		if(mp[v[i]] == 0) ans++;   
		mp[v[i]]++;
    };

    auto rem = [&](int i){
		if(mp[v[i]] == 1) ans--;   
		mp[v[i]]--;
    };

    int q; cin >> q; vector<int> final_ans(q);
    vector<tuple<int, int, int>> qu;
    for(int i = 0; i < q; i++){ int a, b; cin >> a >> b; --a, --b; qu.emplace_back(a, b, i); }
    sort(qu.begin(), qu.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b){
		if(get<0>(a)/B != get<0>(b)/B) return get<0>(a)/B < get<0>(b)/B;
		return get<1>(a) < get<1>(b);
	});

	int l = 0, r = -1;
	for(int i = 0; i < q; i++){
		auto [a, b, c] = qu[i];
		while(r < b) add(++r);
		while(l > a) add(--l);
		while(l < a) rem(l++);
		while(r > b) rem(r--);

		final_ans[c] = ans;
	}

	for(int i = 0; i < q; i++) cout << final_ans[i] << endl;
}

