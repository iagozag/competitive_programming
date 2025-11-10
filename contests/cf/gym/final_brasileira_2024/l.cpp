#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll

int32_t main(){
	int n, q; cin >> n >> q;
	vector<int> r(n), c(n);
	iota(r.begin(), r.end(), 0);
	iota(c.begin(), c.end(), 0);

	for(int i = 0; i < q; i++){
		char ch; int a, b; cin >> ch >> a >> b; --a, --b;
		if(ch == 'R') swap(r[a], r[b]);
		else swap(c[a], c[b]);
	}

	int mat[n][n], rows[n][n+1], cols[n][n+1], cur = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int val = (cur+j)%n+1;
			mat[i][j] = val, rows[i][val] = j, cols[j][val] = i;
		}
		cur++;
	}

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		int val = mat[r[i]][c[j]];

		swap(mat[r[i]][c[j]], mat[r[i]][rows[r[i]][mat[i][j]]]);

		swap(rows[r[i]][mat[i][j]], rows[r[i]][val]);
	}

	for(int i = 0; i < n; i++){
		set<int> st;
		for(int j = 0; j < n; j++) st.insert(mat[i][j]);
		if(st.size() != n) { cout << '*' << endl; return 0; }
	}
	for(int i = 0; i < n; i++){
		set<int> st;
		for(int j = 0; j < n; j++) st.insert(mat[j][i]);
		if(st.size() != n) { cout << '*' << endl; return 0; }
	}

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) 
		cout << mat[i][j] << " \n"[j==n-1];

	exit(0);
}
