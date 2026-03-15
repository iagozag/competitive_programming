#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int n, k; cin >> n >> k;
		cout << (k >= n-1 ? 1 : n) << endl;
	}

	exit(0);
}

