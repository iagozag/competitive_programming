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
	list<char> v;
	map<char, int> cnt;
	for(int i = 0; i < n; i++){
		char c; cin >> c;
		v.push_back(c);
		cnt[c]++;
	}

	if(cnt['T'] == n or cnt['L'] == n or cnt['I'] == n){ cout << -1 << endl; return; }
	
	int ma = max({cnt['L'], cnt['I'], cnt['T']});

	vector<int> ans; auto it = v.begin();
	while((cnt['L'] != cnt['I'] or cnt['L'] != cnt['T']) and (int)ans.size() < 2*n){
		int can = 0;
		for(auto i = it; next(i) != v.end(); i++) if(*i != *(next(i))){
			char diff = (*i)^(*(next(i)))^('T')^('L')^('I');
			if(cnt[diff] < ma){
				ans.emplace_back(distance(v.begin(), i)+1);
				cnt[diff]++;
				v.insert(next(i), diff);
				it = i;
				can = 1;
				break;
			}
		}

		if(!can) ma++;
	}
	
	if(cnt[0] != cnt[1] or cnt[0] != cnt[2]){ cout << -1 << endl; return; }

	cout << ans.size() << endl;
	for(auto x: ans) cout << x << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
