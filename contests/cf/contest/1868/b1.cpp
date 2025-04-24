#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){
	cout << "no" << endl;
}

void solve(){
	int n; cin >> n; int sum = 0;
	vector<int> v(n); for(auto& x: v) cin >> x, sum += x;
	if(sum%n) return no();

	int obj = sum/n; vector<int> need(32);
	for(int i = 0; i < n; i++){
		bool can = 0;
		for(int x = 0; x < 31; x++)  for(int y = 0; y < 31; y++) if(obj == v[i]+(1<<x)-(1<<y)){
			need[x]++, need[y]--;
			can = 1;
		}
		if(!can) return no();
	}

	if(*max_element(need.begin(), need.end())) return no();
	cout << "yes" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
