#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

int32_t main(){ _
    int n, k;
    while(cin >> n >> k){
        vector<int> ans(n);
        int idx = 0;
        for(int i = 0; i < n*k; i++){
            int x; cin >> x; 
            ans[idx] += x;
            idx = (idx+1)%n;
        }

        idx = n-1;
        for(int i = n-2; i >= 0; i--) if(ans[i] > ans[idx]) idx = i;
        cout << idx+1 << endl;
    }

    exit(0);
}