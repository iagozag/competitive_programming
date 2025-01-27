#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;

vector<int> make(vector<int> v){
	vector<int> res; unordered_set<int> has;
	for(int i = 0; i < (int)v.size(); i++){
		int x = v[i];
		while(v[i] <= n){
			int m = res.size();
			if(!has.count(v[i])) res.emplace_back(v[i]);
			for(int j = 0; j < m; j++){
				if(__int128_t(res[j])*__int128_t(v[i]) <= __int128_t(n)){
					int num = res[j]*v[i];
					if(!has.count(num)) res.emplace_back(num), has.insert(num);
				}
			}
			v[i] *= x;
		}
	}
	sort(res.begin(), res.end());
	return res;
}

void solve(){
	int p; cin >> n >> p;

	vector<int> a, b;
	for(int i = 2; i <= p; i++){
		bool can = 1;
		for(int j = 2; j <= sqrt(i); j++) if(i%j == 0) can = 0;
		if(can){
			if(a.size() <= b.size()) a.emplace_back(i);
			else b.emplace_back(i);
		}
	}

	vector<int> x = make(a), y = make(b); int ans = (int)x.size()+(int)y.size();

	int j = (int)y.size()-1;
	for(int i = 0; i < (int)x.size(); i++){
		while(j >= 0 and __int128_t(x[i])*__int128_t(y[j]) > __int128_t(n)) j--;
		ans += j+1;
	}

	cout << ans+1 << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
