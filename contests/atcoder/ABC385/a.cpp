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
	vector<int> v(3); cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());
	if(v[0] == v[1] and v[1] == v[2]) cout << "Yes" << endl;
	else if(v[0]+v[1] == v[2]) cout << "Yes" << endl;
	else cout << "No" << endl;
	
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
