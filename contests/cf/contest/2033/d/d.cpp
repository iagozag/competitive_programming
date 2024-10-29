#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<ll> v(n); for(auto& x: v) cin >> x;
	int ans = 0; ll sum = 0; set<ll> has; has.insert(0);
	for(int i = 0; i < n; i++){
		sum += v[i]; 
		if(has.count(sum)) ans++, has.clear(), has.insert(0), sum = 0;
		else has.insert(sum);
	}
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
