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
	int n; cin >> n;
	queue<int> v; vector<int> ans; multiset<int> st;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		v.push(a), st.insert(a);
	}

	priority_queue<int, vector<int>, greater<int>> ord;
	while(v.size()){
		if(v.front() == (*st.begin())){
			ans.emplace_back(v.front()), v.pop(), st.erase(st.find((*st.begin())));
			while(ord.size()){
				int a = ord.top(); ord.pop();
				v.push(a), st.insert(a);
			}
		} else{
			ord.push(v.front()+1), st.erase(st.find(v.front())), v.pop();
		}
	}
	
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
