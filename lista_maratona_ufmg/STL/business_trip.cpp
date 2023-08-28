#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int k; cin >> k;
    vector<int> centimeters;
    for(int i = 0; i < 12; i++){
        int a; cin >> a;
        centimeters.push_back(a);
    }

    sort(centimeters.begin(), centimeters.end(), greater<int>());
    
    int ans = 0;
    for(auto c: centimeters){
        if(k <= 0) break;
        k -= c;
        ans++;
    }
    (k <= 0) ? cout << ans << endl : cout << -1 << endl;

    exit(0);
}
