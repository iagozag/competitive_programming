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
	int n, m, k; cin >> n >> m >> k;
	string s; cin >> s; vector<int> pref(n+1);
	for(int i = 1; i <= n; i++) pref[i] = pref[i-1]+(s[i-1] == 'x');	

	auto bs = [&](int i, int ma){
		int l = i, r = n-1, idx = i-1;
		while(l <= r){
			int mid = l+(r-l)/2;
			if(pref[mid+1]-pref[i] <= ma) idx = mid, l = mid+1;
			else r = mid-1;
		}
		return idx;
	};

	int ans = 0;
	for(int i = 0; i < n; i++){
		int sum = 0;
		if(pref[n]-pref[i] > k) sum = bs(i, k)-i+1;
		else{
			sum = n-i;
			int tmp = k-(pref[n]-pref[i]);
			if(tmp/pref[n] < m-1){
				sum += (tmp/pref[n])*n;
				tmp %= pref[n];
				sum += bs(0, tmp)+1;
			}
			else sum += n*(m-1);
		}
		ans = max(ans, sum);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
