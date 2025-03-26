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

	int ans = 0;
	if(k == 1){
		for(int i = 0; i < n; i++){
			if(i) ans = max(ans, v[i]+v[0]);
			if(i < n-1) ans = max(ans, v[i]+v[n-1]);
		}
		cout << ans << endl;
		return;
	}

	for(int i = 0; i < n; i++){
		int sum = v[i];
		vector<int> left(n), right(n);
		for(int j = 0; j < i; j++) left[j] = v[j];
		for(int j = i+1; j < n; j++) right[j] = v[j];
		sort(left.begin(), left.end(), greater<int>());
		sort(right.begin(), right.end(), greater<int>());

		if(i > 0 and i < n-1){
			int l = 1, r = 1;

			sum += left[0]+right[0]; int qnt = 2;

			while(qnt < k){
				if(left[l] > right[r]) sum += left[l], l++;
				else sum += right[r], r++;
				qnt++;
			}
			ans = max(ans, sum);
		}

		left = right = vector<int>(n);
		for(int j = 0; j < i; j++) left[j] = v[j];
		for(int j = i+1; j < n; j++) right[j] = v[j];

		sum = 0; int l = 0, r = 0;

		if(i >= k) for(int j = 0; j < k; j++){
			sum += left[l++];
		}
		ans = max(ans, sum);
		sum = 0;
		if(n-i-1 >= k) for(int j = 0; j < k; j++){
			sum += right[r++];
		}
		ans = max(ans, sum);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
