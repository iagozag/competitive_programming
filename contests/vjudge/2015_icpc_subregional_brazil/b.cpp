#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define int long long
typedef long long ll;


int32_t main(){ _ 
    
    int n, c;
    while(cin >> n >> c){
    
        ll dp[n+1];
        int mr[1001];
        for(int i = 0; i < 1001; i ++) mr[i]=-1;
        ll arr[n+1];
        for(int i = 0; i < n; i ++){
            cin >> arr[i];
            dp[i] = (i == 0) ? 0 : dp[i-1];
            for(int j = arr[i]; j >= 1; j--){
                if(mr[j] != -1)
                dp[i] = max(dp[i], (arr[i] - arr[mr[j]] -c) + (mr[j] > 0 ? dp[mr[j]-1]:0));
            }   
            mr[arr[i]]=i;
        }
        cout << dp[n-1] << endl;

        //for(int i = 0; i < n; i ++) cout << dp[i] << " ";
        //cout << endl;
    }


    exit(0);
}