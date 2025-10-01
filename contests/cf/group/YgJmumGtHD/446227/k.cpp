#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define int long long

const int INF = 0x3f3f3f3f;

int32_t main(){ _
	int n; cin >> n;
	vector<int> r(n), g(n), b(n);
	for(int i = 0; i < n; i++) cin >> r[i] >> g[i] >> b[i];
	
	int br, bg, bb, ma = 0;
	for(int i = 0; i < 256; i++) for(int j = 0; j < 256; j++) for(int k = 0; k < 256; k++){
		int d = INF;
		for(int p = 0; p < n; p++){
			int nd = abs(r[p]-i)+abs(g[p]-j)+abs(b[p]-k);
			if(nd < d) d = nd;
		}
		if(d > ma) br = i, bg = j, bb = k, ma = d;
	}

	cout << br << ' ' << bg << ' ' << bb << endl;
	exit(0);

}
