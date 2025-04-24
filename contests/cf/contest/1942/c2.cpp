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
	int n, x, y; cin >> n >> x >> y;
	vector<int> v(x); for(auto& z: v) cin >> z;
	sort(v.begin(), v.end());

	int ans = x-2;
	for(int i = 0; i < x; i++){
		if((v[i]+1)%n == ((v[(i+1)%x]-1)+n)%n) ans++;
	}

	for(int i = 0; i < x; i++){
		if(y and (v[i]+2)%n == ((v[(i+1)%x]-2)+n)%n) ans += 3, y--;
	}

	for(int i = 0; i < x; i++){
		if(y and (v[i]+1)%n == ((v[(i+1)%x]-2)+n)%n) ans += 2, y--;
	}

	cout << min(ans+y, n-2) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
