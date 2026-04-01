#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

const int LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
    int n; 
    while(cin >> n){
        vector<pair<int, int>> arr(n);
        for(auto& [a,b] : arr) cin >> a >> b;
        sort(arr.begin(), arr.end());

        int res = 0;
        for(int i = 0; i < n; i ++){
            auto [a, b] = arr[i];
            int miny = -LINF, maxy = LINF;
            for(int j = i+1; j < n; j ++) {
                auto [c, d] = arr[j];
                res += (d < maxy and d > miny) ;
                if(d <= b) miny = max(d, miny);
                if(d >= b) maxy = min(d, maxy);
            }
        }
        cout << res << endl;
    }

    exit(0);
}