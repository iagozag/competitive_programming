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

int main(){ // _
    int n, x, anterior = 1, dist, ans = 0; cin >> n >> x;
    int t1, t2;

    for(int i = 0; i < n; i++){
        cin >> t1 >> t2;

        dist = (t1 - anterior) % x;
        if(dist == 0) ans += t2 - t1 + 1;
        else ans += t2 - (t1 - dist) + 1;

        anterior = t2+1;
    }

    cout << ans << endl;
    return(0);
}
