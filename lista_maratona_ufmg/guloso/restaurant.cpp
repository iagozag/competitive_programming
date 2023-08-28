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
    int orders, a, b, ans = 0; cin >> orders;
    vector<ii> times;

    for(int i = 0; i < orders; i++){
        cin >> a >> b;
        times.pb({a, b});
    }
    
    sort(times.begin(), times.end());

    int prev = INF;
    for(int i = orders-1; i >= 0; i--){
        if(times[i].s < prev){
            ans++;
            prev = times[i].f;
        }
    }

    cout << ans << endl;
    exit(0);
}
