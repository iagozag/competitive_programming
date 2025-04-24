#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main() { _
    vector<int> arr(3); for(auto& el: arr) cin >> el;
    
    sort(arr.rbegin(), arr.rend());
    if(arr[0] >= arr[1] + arr[2]){
        cout << "S\n";
    } else cout << "N\n";

}