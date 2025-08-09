#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
#define int ll

vector<vector<int>> ladj;
vector<int> temps; 
vector<int> pr;
vector<int> vis;
int n, k; 

int dfs(int v){
    int s = 0;
    vis[v] = 1;
    for(auto u : ladj[v]){
        if(!vis[u]){
            pr[u] = pr[v] + 1;
            s+=dfs(u);
        }   
    }

	if(v != 0 and (s > 0 or temps[v] > k)) s += 2;

    return s;
}

int32_t main(){ _
    cin >> n >> k;
    int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        temps.push_back(t);
    }

    ladj.resize(n);
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b; --a, --b;
        ladj[a].push_back(b);
        ladj[b].push_back(a);
    }

	pr.assign(n, 0);
	vis.assign(n, 0);
	int n_arst = dfs(0);
	int max_pr = 0;
	for(int i = 0; i < n; i++){
		if(temps[i] > k)
			max_pr = max(max_pr, pr[i]);
	}
	cout << n_arst-(max_pr) << endl;

	exit(0);
};

