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
    int n, ans = 0; cin >> n;
    map<int,int> mp;
    while(n--){
        int a; cin >> a;
        if(mp.count(a) > 0) mp.at(a)++;
        else mp.insert({a,1});
    }

    for(auto e: mp){
        if(e.second < 2) continue;
        if(e.second % 2 == 1) e.second--;
        ans += e.second;
    }

    ans /= 4;
    cout << ans << endl;

    exit(0);
}
