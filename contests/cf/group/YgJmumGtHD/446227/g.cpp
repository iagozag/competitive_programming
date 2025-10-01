#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define int long long

int32_t main(){ _
	int n; cin >> n;
	int ans = 2;
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		if(a == ans) ans = b;
		else if(b == ans) ans = a;
	}

	cout << ans << endl;
	exit(0);

}
