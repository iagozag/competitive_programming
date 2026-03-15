#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int32_t main(){
    int n;
	while(cin >> n and n){
		stack<int> st; int want = 1;
		for(int i = 0; i < n; i++){
			int num; cin >> num;
			while(st.size() and st.top() == want){
				want++; st.pop();
			}
			if(num == want) want++;
			else st.push(num);
		}
		while(st.size() and st.top() == want) want++, st.pop();

		if(want == n+1) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
