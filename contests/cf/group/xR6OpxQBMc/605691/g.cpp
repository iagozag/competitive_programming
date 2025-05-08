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
	cout << "No" << endl;
}

void yes(){
	cout << "Yes" << endl;
}

void solve(){
	int n; cin >> n;
	vector<int> v(n);for(auto & x: v) cin >> x;

	sort(v.begin(), v.end());

	if(v.back()-v[0] >= 2) return no();

	if(v[0] == v.back()) return (n >= v[0]*2 or v[0] == n-1 ? yes() : no());

	int i = 1;
	while(v[i] == v[0]) i++;

	if(v[0] < i) return no();

	int need = v[0]-i+1;
	return (need*2 <= n-i ? yes() : no());
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
