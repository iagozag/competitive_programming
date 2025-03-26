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
	int n, k; cin >> n >> k;
	vector<int> v(n); for(auto& x: v) cin >> x;
	
	priority_queue<int> pq; int can = 0, ans = 0;
	for(int i = n-1; i >= 0; i--){
		can++;
		if(can <= k){
			if(!pq.empty() and v[i] > -pq.top())
				ans += v[i]+pq.top(), pq.pop(), pq.push(-v[i]);
		} else{
			ans += v[i], can -= k+1, pq.push(-v[i]);
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
