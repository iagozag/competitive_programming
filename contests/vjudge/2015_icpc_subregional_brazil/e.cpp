#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

const int LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
    int n, b;
    while(cin >> n >> b){
        pair<int, int> ans = {1, 1};

        int l = 0, r = (n+1)/2-1, qnt;
        while(l <= r){
            int mid = l+(r-l)/2;

            int len = n-2*mid;
            if(b >= n*n - len*len) qnt = mid, l = mid+1;
            else r = mid-1;
        }
        ans.first += qnt, ans.second += qnt;

        int len = n-2*qnt;
        b -= n*n - len*len;

        if(b > len){
            ans.second += len-1;
            ans.first++;
            b -= len;

            len--;
            if(b > len){
                ans.first += len-1;
                ans.second--;
                b -= len;

                if(b > len){
                    ans.second -= len-1;
                    ans.first--;
                    b -= len;

                    len--;
                    if(b) ans.first -= b-1;
                }
                else ans.second -= b-1;
            }
            else ans.first += b-1;
        }
        else ans.second += b-1;

        cout << ans.first << ' ' << ans.second << endl;
    }

    exit(0);
}