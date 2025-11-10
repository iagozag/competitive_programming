#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll

int32_t main(){
	string s; cin >> s;
	set<char> st;
	for(auto x: s) st.insert(x);

	cout << s.size()-st.size() << endl;
	exit(0);
}
