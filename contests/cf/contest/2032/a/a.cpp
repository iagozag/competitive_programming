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
	vector<int> v(2*n); for(auto& x: v) cin >> x;
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < 2*n; i++){
		if(v[i]) cnt1++;
		else cnt0++;
	}

	cout << (cnt0&1) << " " << min(cnt0, cnt1) << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
