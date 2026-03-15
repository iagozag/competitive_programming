#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'

int32_t main(){ _
    int n; cin >> n;
    for(int i = 0; i < n; i++){
	string a, b; cin >> a >> b;

	reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
	int numa = stoi(a), numb = stoi(b);
	int sum = numa+numb;

	string ssum = to_string(sum);
	reverse(ssum.begin(), ssum.end());
	sum = stoi(ssum);
	cout << sum << endl;
    }
}
