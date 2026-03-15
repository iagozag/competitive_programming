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
	string s; cin >> s; int n = s.size();

	vector<int> height(n);
	stack<tuple<int, int, int>> st; int open = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '(') st.push({1, 1, 0}), open++;
		else{
			auto [h, b, qnt] = st.top(); st.pop();

			b += qnt;
			ans += (open&1 ? 1 : -1)*h*b;
			open--;

			if(!st.empty()){
				auto [h1, b1, qnt1] = st.top(); st.pop();
				b1 += b, h1 = max(h1, h+1), qnt1++;
				st.push({h1, b1, qnt1});
			}
		}
	}

	cout << ans << endl;

}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
