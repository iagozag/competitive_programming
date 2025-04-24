#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){
	cout << "No" << endl;
}

void solve(){
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	int i = n-1, j = n-1; multiset<int> st;
	while(i >= 0 and j >= 0){
		while(j and b[j] == b[j-1]) st.insert(b[j--]);
		if(a[i] == b[j]) i--, j--;
		else if(!st.count(a[i])) return no();
		else st.erase(st.find(a[i--]));
	}

	cout << "Yes" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
