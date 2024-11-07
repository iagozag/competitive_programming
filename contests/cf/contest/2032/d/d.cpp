#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int query(int a, int b){
	cout << "? " << a << " " << b << endl;
	int c; cin >> c;
	return c;
}

void solve(){
	int n; cin >> n;
	vector<int> ans(n+1);
	int c;
	for(int i = 2; i < n; i++){
		if(query(i, 1) == 0){ c = i; break; }
	}

	queue<int> have;
	vector<int> child(n+1); iota(child.begin(), child.end(), 0);
	ans[c] = 1, child[1] = c, have.push(1); 

	if(c+1 < n){
		int k = c+1;
		for(int i = 1; i < c; i++){
			if(query(i, k) == 0) ans[k] = child[i], have.push(i), child[i] = k++;
			if(k >= n) break;
		}

		while(k < n){
			auto x = have.front(); have.pop();
			if(have.size() == 0){
				while(k < n) ans[k] = child[x], child[x] = k, k++;
				break;
			}
			
			if(query(k, x) == 0) ans[k] = child[x], child[x] = k, k++, have.push(x);
		}
	}

	cout << "! ";
	for(int i = 1; i < n; i++) cout << ans[i] << " \n"[i==n-1];
}

int main(){
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
