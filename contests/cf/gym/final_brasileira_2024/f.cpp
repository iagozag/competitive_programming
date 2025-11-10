#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll

bool no(){
	cout << '*' << endl;
	return 0;
}

int32_t main(){
	int k, n; cin >> k >> n;

	vector<int> dp(n); dp[n-1] = 1; if(n >= 2) dp[n-2] = 1;
	for(int i = n-3; i >= 0; i--) dp[i] = dp[i+2]+1;

	vector<int> v(n); int j = 0;
	while(j < n and k){
		if(j+1 < n and dp[j+1] >= k) j++;

		v[j] = 1;
		j += 2;
		k--;
	}

	bool ok = 1;
	for(int i = 0; i < n; i++){
		int sum = 0;
		if(i-1 >= 0) sum += v[i-1];
		if(i+1 < n) sum += v[i+1];

		if(v[i] and sum) ok = 0;
		sum += v[i];
		if(sum == 0) ok = 0;
	}

	if(!ok or k != 0) return no();

	for(int i = 0; i < n; i++) cout << (v[i] ? 'X' : '-');
	cout << endl;

	exit(0);
}
